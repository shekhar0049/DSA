int n;
char ch ;
cin>> n;
cout << "what do u want sum of :";
cin >> ch;
int sum= 0;
 if(ch == 'e'){

   int i= 2;
   while (i<=n){
   sum = sum + i;
   i= i+2; 
    
   } 
   cout << sum << endl;
 } 
