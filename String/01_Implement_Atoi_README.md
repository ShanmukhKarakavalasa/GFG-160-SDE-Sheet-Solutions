Given a string s, the objective is to convert it into integer format without utilizing any built-in functions. Refer the below steps to know about atoi() function.

Cases for atoi() conversion:

1. Skip any leading whitespaces.

  
2. Check for a sign (‘+’ or ‘-‘), default to positive if no sign is present.

 
3. Read the integer by ignoring leading zeros until a non-digit character is encountered or end of the string is reached. 

4. If no digits are present, return 0.

  
5. If the integer is greater than 231 – 1, then return 231 – 1 and if the integer is smaller than -231, then return -231.
