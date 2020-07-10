<!DOCTYPE html>
<html>
<head>
<title>Assignment 5</title>
<style>body 
{background-color: white;
  text-align: center;
  color: black;
  font-family: verdana;}
  
h1, h2{text-align:left;}

table, th, td {padding:5x;
border: 1px solid black;}

p{text-align:left;}

#radio{margin-left:25px;}

#street{margin-left: 120px;}

#city{margin-left: 138px;}

#states{margin-left: 125px;}

#zip-code{margin-left: 95px;}

#table{text-align: left;}

.class-item{}

#reset{float:left;;}

#submit{margin-right:10px;
float:left;}

.row-item{width:20px;}


</style>
</head>
<body>
	<h1>Widget Ordering System</h1>
	<hr>
	<div>
		<h2> Customer Information</h2>
        	<form method="post" action="process.php">
        		<p>Customomer Type: 
            	<input type="radio" name="type" value="Premier" id= "radio"> Premier
            	<input type="radio" name="type" value="Elite" checked="checked" > Elite
            	</p>
				
            	<p>Customer First Name:
                <input type="text" name="fname"/>
                </p>
				
                <p>Customer Last Name:
                <input type="text" name="lname"/>
                </p>
				
                <p>Street:
                <input type="text" name="street" id="street"/>
                </p>
				
                <p>City:
                <input type="text" name="city" id="city"/>
                </p>
				
                <p>State:
                <select name="states" id="states">
                  <option value="CT">CT</option>
                  <option value="MA">MA</option>
                  <option value="NH">NH</option>
                  <option value="RI" selected="selected">RI</option>
                 
                  <option value="VT">VT</option>
				  <option value="ME">ME</option>
                  
                </select>
                </p>
				
                <p>Zip Code:
                <input type="text" name="zip-code test" id="zip-code" size="5"/>
                </p>
            
	</div>
    <div>
		<h2>Order Information</h2>
          
            <table style="width:32.5%" id="table">
              <tr>
                <th width="1%">QTY</th>
                <th width="15%" >Item</th> 
                <th width="5%">Item Price</th>
              </tr>
              <tr>
			  
                </td><td><input type='text' name ="qty1" class="row-item" value="0"/></td>
			  
                <td>Widget #8493 - Extra Crunchy</td>
                <td align="right">$ 5.71</td>
              </tr>
              <tr>
               
                </td><td><input type='text' name ="qty2" class="row-item" value="0"/></td>
                <td>Widget #3423 - Super Slippery</td>
                <td align="right">$ 4.21</td>
              </tr>
              <tr>
               
                </td><td><input type='text' name ="qty3" class="row-item" value="0"/></td>
                <td>Widget #2382 - Very Wobbly</td>
                <td align="right">$ 2.51</td>
              </tr>
              <tr>
              
                </td><td><input type='text' name ="qty4" class="row-item" value="0"/></td>

               <td>Widget #4523 - Extremely Sticky</td>
               <td align="right">$ 1.21</td>
             </tr>
              <tr>
              
               </td><td><input type='text' name ="qty5" class="row-item" value="0"/></td>
               <td>Widget #6851 - Wonderfully Wacky</td>
               <td align="right">$ 8.51</td>
             </tr>
			 
            </table><br>
            <button type="submit" name="button" value="Submit" id="submit">Submit</button><button type="reset" value="Reset" id="reset">Reset Your Order Form</button>
            
			</form>
		  <br>

    </div>
	<hr>
</body>
</html>