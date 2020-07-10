<!DOCTYPE html>
<html>
	<head>
		<title>Assignment 5</title>
		<style type="text/css">
			body {font-family:"Courier New";}
			table {border:2px solid black; border-collapse:collapse;}
			th, td {border:2px solid black;text-align:left; vertical-align:top;}
		</style>
	</head>
	<h1>Widget Ordering System</h1>
	<hr>
	<h2>Order Confirmation</h2>
	
		<?php
			
		    $db = new mysqli("localhost", "root","","store");
			

			if ($db->connect_errno)
			{
				echo "Failed to connect to MySQL: (". $db->connect_errno . " ) " . $db->connect_error;
				die('Goodbye');
			}
			
			if(!$_POST)
			{
				die ("<p>Error 401 not found<br>");
			}
			else
			{
				$type = $_POST['type'];
				$fname = $_POST['fname'];
				$lname = "";
				$states = $_POST['states'];
				$lname = $_POST['lname'];
				$street = $_POST['street'];
				$city = $_POST['city'];
				$zip_code = $_POST['zip-code'];
				$qty1 = $_POST['qty1'];
				$qty2 = $_POST['qty2'];
				$qty3 = $_POST['qty3'];
				$qty4 = $_POST['qty4'];
				$qty5 = $_POST['qty5'];
				$db_price = 0;
				$cid = 0;
				$ec = 0;
				$ss = 0;
				$vw = 0;
				$es = 0;
				$ww = 0;
				$ec_total = 0;
				$ss_total = 0;
				$vw_total = 0;
				$es_total = 0;
				$ww_total = 0;
				$null = "NULL";
				$total_1 = number_format(($qty1 * 5.71),2);
				$total_2 = number_format(($qty2*4.21),2);
				$total_3 = number_format(($qty3*2.51),2);
				$total_4 = number_format(($qty4*1.21),2);
				$total_5 = number_format(($qty5*8.51),2);
				$product_total = $total_1 + $total_2 + $total_3 + $total_4  + $total_5;
				$final_cost = 0;
				
				
				if ($type!="elite")
					$final_cost = $product_total;
				
				else
				$final_cost = number_format($product_total -($product_total *.20),2);
				$query = "SELECT cfname, clname, czip, cid FROM customers";
				$result = $db->query($query);
				$truth = false;
				
				while($rows = $result->fetch_assoc())
				{
					if(($fname == $rows['cfname']) && ($lname == $rows['clname']) && ($zip_code == $rows['czip']))
					{	
						$truth = true;
						$cid = $rows['cid'];
						$lname = $rows['clname'];
					}
					
					else
					{
						$cid = $rows['cid']+1;
					}
				}
				
				if($truth ==true)
				{
					echo "<p>Welcome back $fname,  </p><p>Thank you. Your order was submitted successfully!</p>";
					echo "<hr>";
				}
				else
				{	
					$sql = "INSERT INTO customers VALUES"."('$null', '$fname', '$lname' , '$street' ,'$city','$states','$zip_code','$type')";
					if ($db->query($sql)== true) {  
				} 
		
					else
					{ 
						echo "ERROR: Could not able to execute $sql. ".$db->error; 
					} 
					
					
				echo "<p>Welcome to our store $fname! We have added you to our customer database. </p><p>Thank you. Your order was submitted successfully!</p>";
				echo "<hr>";
				}
				
				
				$tz = 'US/Eastern';
				$timestamp = time();
				$dt = new DateTime("now", new DateTimeZone($tz));
				$dt-> setTimestamp($timestamp);
				$time = $dt->format('Y-m-d H:i:s');
				$sql = "INSERT INTO orders VALUES" ."('$null', '$cid', '$qty1', '$qty2','$qty3', '$qty4', '$qty5','$time','$product_total')";
				
				
				if ($db->query($sql)== true)
				{ } 
					else
					{ 
						echo "ERROR: Could not able to execute $sql. ".$db->error; 
					} 
					
				$query = "SELECT qty_8493, qty_3423, qty_2382, qty_4523, fprice,qty_6851  FROM orders Where cid = $cid";
				
				$result = $db->query($query);
				while($rows = $result->fetch_assoc()){
					$ec = $ec+$rows['qty_8493'];
					$ss = $ss+$rows['qty_3423'];
					$vw = $vw+$rows['qty_2382'];
					$es = $es+$rows['qty_4523'];
					$ww = $ww+$rows['qty_6851'];
				}
				
				$ec_total = number_format(($ec * 5.71),2);
				$ss_total = number_format(($ss*4.21),2);
				$vw_total = number_format(($vw*2.51),2);
				$es_total = number_format(($es*1.21),2);
				$ww_total = number_format(($ww*8.51),2);
				
				echo "<table style='width:32.5%' id='table'>
				<h2>Sales Report For All Orders<h2>
				
              <tr>
                <th width='1%'>QTY</th>
                <th width='15%' >Item</th> 
                <th width='5%'>Item Price</th>
              </tr>
			  
              <tr>
                </td><td>$ec</td>
                <td>Widget #8493 - Extra Crunchy</td>
                <td style='text-align:right;'>$ $ec_total</td>
              </tr>
			  
              <tr> 
                </td><td>$ss</td>
                <td>Widget #3423 - Super Slippery</td>
                <td style='text-align:right;'>$ $ss_total</td>
              </tr>
			  
              <tr>               
                </td><td>$vw</td>
                <td>Widget #2382 - Very Wobbly</td>
                <td style='text-align:right;'>$ $vw_total</td>
              </tr>
			  
              <tr>
                </td><td>$es</td>
               <td>Widget #4523 - Extremely Sticky</td>
               <td style='text-align:right;'>$ $es_total</td>
             </tr>
			 
              <tr> 
               </td><td>$ww</td>
               <td>Widget #6851 - Wonderfully Wacky</td>
               <td style='text-align:right;''>$ $ww_total</td>
             </tr>
			 <tr>
			 
            </table>
			<br>";
			
			echo "<table>
			<tr>
				<th>Order Number</th>
				<th>Order Date</th>
				<th>Customer</th>
			<th>Final Total</th>
			</tr>";
			
			$query1 = "SELECT * FROM orders WHERE cid = $cid ORDER BY orderno DESC ";
			$result=$db->query($query1);
			
			while($row = $result->fetch_assoc())
			{
			echo "<tr>";
			echo "<td>" . $row['orderno'] . "</td>";
			echo "<td>" . $row['orderdate'] . "</td>";
			echo "<td> $fname $lname</td>";
			echo "<td>" . $row['fprice'] . "</td>";
			echo "</tr>";
			}
			echo "</table>";			
				
			}
			
			$cid = 0;
			mysqli_close($db);
		?>
	<br>
	<a href="http://localhost/widgets.php"> Click Here to submit another order!</a>
	</div>
		
	</body>
</html>