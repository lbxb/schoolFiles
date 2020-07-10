#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

typedef stack<int> lgInt;
bool getLargeNumber(lgInt &ln, string numStr = "");
string ConvertToString(lgInt ln);
bool isLessThan(lgInt op1, lgInt op2);
void putLargeNumber(lgInt ln, string msg = "");
lgInt addLargeNumbers(lgInt op1, lgInt op2);
lgInt subtractLargeNumbers(lgInt op1, lgInt op2);
lgInt multiplyLargeNumbers(lgInt op1a, lgInt op1b, lgInt op2);
lgInt divideLargeNumbers(lgInt op1, lgInt op2);
lgInt moduloLargeNumbers(lgInt op1, lgInt op2);
lgInt poweringLargeNumbers(lgInt op1a, lgInt op1b, lgInt op2);

int main(void){
lgInt x, y, result, one; one.push(1);
string input, CAPSinput = "";
string error[2] = { "Error: invalid input", "Error: negative result" };
vector < string > errorList;
bool test = false;
getLargeNumber(x, "0");
cout << "LARGE NUMBER CALCULATOR" << endl;
do {
cout << "===========================================================" << endl;
cout << "Input {C, E, S, +, -, *, /, %, ^}: ";
cin >> input;
CAPSinput.replace(CAPSinput.begin(), CAPSinput.end(), "");
for (string::size_type i = 0; i < input.size(); i++)
CAPSinput += toupper(input[i]);
// =========================================================================
if (CAPSinput == "C"
|| CAPSinput == "E"
|| CAPSinput == "S"
|| CAPSinput == "+"
|| CAPSinput == "-"
|| CAPSinput == "*"
|| CAPSinput == "/"
|| CAPSinput == "%"
|| CAPSinput == "^")
test = true;
if (test == false){
cout << error[0] << endl;
errorList.push_back(error[0]);
}
test = false;
// =========================================================================
// C
if (CAPSinput == "C")
putLargeNumber(x, "The current integer = ");
// =========================================================================
// E
if (CAPSinput == "E")
for (unsigned int i = 1; i <= errorList.size(); i++)
cout << i << ". " << errorList[i-1] << endl;
// =========================================================================
// add
if (CAPSinput == "+"){
cout << "Enter a positive integer:\n? ";
if (getLargeNumber(y)){
result = addLargeNumbers(x, y);
putLargeNumber(result, "The result is ");
getLargeNumber(x, ConvertToString(result));
}
else{
cout << error[0] << endl;
errorList.push_back(error[0]);
}
}
// =========================================================================
// subtract
if (CAPSinput == "-"){
cout << "Enter a positive integer:\n? ";
if (getLargeNumber(y)){
if (!isLessThan(x, y)){
result = subtractLargeNumbers(x, y);
putLargeNumber(result, "The result is ");
getLargeNumber(x, ConvertToString(result));
}
else{
cout << error[1] << endl;
errorList.push_back(error[1]);
}
}
else{
cout << error[0] << endl;
errorList.push_back(error[0]);
}
}
// =========================================================================
// mulitiply
if (CAPSinput == "*"){
cout << "Enter a positive integer:\n? ";
if (getLargeNumber(y)){
result = multiplyLargeNumbers(x, x, y);
putLargeNumber(result, "The result is ");
getLargeNumber(x, ConvertToString(result));
}
else{
cout << error[0] << endl;
errorList.push_back(error[0]);
}
}
// =========================================================================
// divide
if (CAPSinput == "/"){
cout << "Enter a positive, non-zero integer:\n? ";
if (getLargeNumber(y)){
if (!isLessThan(y, one)){
result = divideLargeNumbers(x, y);
putLargeNumber(result, "The result is ");
getLargeNumber(x, ConvertToString(result));
}
else{
cout << error[0] << endl;
errorList.push_back(error[0]);
}
}
else{
cout << error[0] << endl;
errorList.push_back(error[0]);
}
}
// =========================================================================
// modulo
if (CAPSinput == "%"){
cout << "Enter a positive, non-zero integer:\n? ";
if (getLargeNumber(y)){
if (!isLessThan(y, one)){
result = moduloLargeNumbers(x, y);
putLargeNumber(result, "The result is ");
getLargeNumber(x, ConvertToString(result));
}
else{
cout << error[0] << endl;
errorList.push_back(error[0]);
}
}
else{
cout << error[0] << endl;
errorList.push_back(error[0]);
}
}
// =========================================================================
// power
if (CAPSinput == "^"){
cout << "Enter a positive integer:\n? ";
if (getLargeNumber(y)){
result = poweringLargeNumbers(x, x, y);
putLargeNumber(result, "The result is ");
getLargeNumber(x, ConvertToString(result));
}
else{
cout << error[0] << endl;
errorList.push_back(error[0]);
}
}
} while (CAPSinput != "S");
return 0;
}

bool getLargeNumber(lgInt &ln, string numStr){
while (!ln.empty())
ln.pop();
if (numStr == "")
cin >> numStr;
for (char c : numStr)
{
if (!isdigit(c))
return false;
else
ln.push(c - '0');
}
return true;
}

string ConvertToString(lgInt ln){
string number = "", digit;
vector<int> digits;
while (!ln.empty()){
digits.insert(digits.begin(), ln.top());
ln.pop();
}
for (vector<int>::size_type i = 0; i < digits.size(); i++){
digit = to_string(digits[i]);
number = number + digit;
}
return number;
}

void putLargeNumber(lgInt ln, string msg){
cout << msg;
vector<int>digits;
while (!ln.empty()){
digits.insert(digits.begin(), ln.top());
ln.pop();
}
for (auto d : digits)
cout << d;
cout << endl;
}

lgInt addLargeNumbers(lgInt op1, lgInt op2){
lgInt resultStack, resultStackReversed;
int carry, digitSum, unitPart;
carry = 0;
while (!op1.empty() || !op2.empty()){
digitSum = carry;
if (!op1.empty()){
digitSum += op1.top();
op1.pop();
}
if (!op2.empty()){
digitSum += op2.top();
op2.pop();
}
unitPart = digitSum % 10;
carry = digitSum / 10;
resultStack.push(unitPart);
}
if (carry != 0)
resultStack.push(carry);
while (!resultStack.empty()){
resultStackReversed.push(resultStack.top());
resultStack.pop();
}
return resultStackReversed;
}

lgInt subtractLargeNumbers(lgInt op1, lgInt op2){
lgInt resultStack, resultStackReversed;
int digitSum, unitPart, z = 0;
while (!op1.empty() || !op2.empty()){
digitSum = 0;
if (!op1.empty()){
digitSum += op1.top();
op1.pop();
}
if (!op2.empty()){
digitSum -= op2.top();
op2.pop();
}
if (digitSum - z < 0){
unitPart = digitSum + 10 - z;
z = 0;
z++;
}
else{
unitPart = digitSum - z;
z = 0;
}
resultStack.push(unitPart);
}

while (!resultStack.empty()){
if (resultStack.top() == 0 && resultStack.size() > 1)
resultStack.pop();
else
break;
}
while (!resultStack.empty()){
resultStackReversed.push(resultStack.top());
resultStack.pop();
}
return resultStackReversed;
}

lgInt multiplyLargeNumbers(lgInt op1a, lgInt op1b, lgInt op2){
lgInt one; one.push(1);
while (!isLessThan(op2, one)){ 
op1a = addLargeNumbers(op1a,op1b);
op2 = subtractLargeNumbers(op2, one);
}
return subtractLargeNumbers(op1a, op1b); // b/c we want while(op2 < two), not while (op2 < one)
}

bool isLessThan(lgInt op1, lgInt op2){ // return op1 < op2
vector<int>leftside;
while (!op1.empty()){
leftside.insert(leftside.begin(), op1.top());
op1.pop();
}
vector<int>rightside;
while (!op2.empty()){
rightside.insert(rightside.begin(), op2.top());
op2.pop();
}

if (leftside.size() > rightside.size())
return false;
else if (leftside.size() < rightside.size())
return true;
else { // if (leftside.size() == rightside.size())
while (leftside.size() != 0){
if (leftside[0] > rightside[0])
return false;
else if (leftside[0] < rightside[0])
return true;
else {
leftside.erase(leftside.begin());
rightside.erase(rightside.begin());
}
}
return false;
}
}

lgInt divideLargeNumbers(lgInt op1, lgInt op2){
lgInt count; count.push(0);
lgInt one; one.push(1);
while (!isLessThan(op1, op2)){
op1 = subtractLargeNumbers(op1, op2);
count = addLargeNumbers(count, one);
}
return count;
}

lgInt moduloLargeNumbers(lgInt op1, lgInt op2){
while (!isLessThan(op1, op2))
op1 = subtractLargeNumbers(op1, op2);
return op1;
}

lgInt poweringLargeNumbers(lgInt op1a, lgInt op1b, lgInt op2){
lgInt one; one.push(1);
lgInt two = addLargeNumbers(one, one);
while (!isLessThan(op2, two)){
op1a = multiplyLargeNumbers(op1a, op1a, op1b);
op2 = subtractLargeNumbers(op2, one);
}
return op1a; // b/c we want while(op2 < two), not while (op2 < one)
}

// =========================================================================================================
// FANCY BUT SUCKY RECURSIONS

//lgInt multiplyLargeNumbers(lgInt op1a, lgInt op1b, lgInt op2, lgInt one){
// if (op2.size() == 1 && op2.top() == 0){
// lgInt zero; zero.push(0); return zero;
// }
// else if (op2.size() == 1 && op2.top() == 1)
// return op1a;
// else 
// return multiplyLargeNumbers(addLargeNumbers(op1a, op1b), op1b, subtractLargeNumbers(op2, one), one);
//} 

//lgInt divideLargeNumbers(lgInt op1, lgInt op2, lgInt one, lgInt count){ // count = 0
// if (isLessThan(op1, op2))
// return count;
// else
// return divideLargeNumbers(subtractLargeNumbers(op1, op2), op2, one, addLargeNumbers(count, one));
//}

//lgInt moduloLargeNumbers(lgInt op1, lgInt op2, lgInt one){
// if (isLessThan(op1, op2))
// return op1;
// else
// return moduloLargeNumbers(subtractLargeNumbers(op1, op2), op2, one);
//}
// =========================================================================================================