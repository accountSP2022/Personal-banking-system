   #include <iostream>
    #include <fstream>
    #include <string>
    #include <cstdlib>
    #include <iomanip>
    #include <cmath>

              using namespace std;


                  struct money{

                  string desc;
                  string str; //d or w check
                  string amount;
                  string bal;
                  string check; //number
                  string date;

                  money *next;

              };//end

              void title();
              void transition();
              void error(string msg);
              void exit();
              money* input( );
              void edit(money *ptr);
              void output(money *ptr);
              void menu( );
              void print(money *ptr);
              money* search_description(money *ptr);
              money* search_checknumber(money *ptr);
              void menu_2( money *ptr );
              void print_one( money *ptr );

              void saveFile(money* mptr);
              money* readFile();

              int main()
              {
                  money m;
                  title();
                  transition();
                  menu();
                  return 0;
              }//end int main


    //_________________________________________________________________________________________

      void title(){
                  cout << "                $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
                  cout << "                $$                                       $$" << endl;
                  cout << "                $$                                       $$" << endl;
                  cout << "                $$          Sarena's Personal            $$" << endl;
                  cout << "                $$          Check Register               $$" << endl;
                  cout << "                $$                                       $$" << endl;
                  cout << "                $$             $   $  $                  $$" << endl;
                  cout << "                $$                                       $$" << endl;
                  cout << "                $$                                       $$" << endl;
                  cout << "                $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
                  cout << "                                   $$                      "  << endl;
                  cout << "                                   $$                      "  << endl;
                  cout << "                                   $$                      "  << endl;
                  cout << "                                   $$                      "  << endl;
                  cout << "                              $$$$$$$$$$$$                 "  << endl;

                  cout << endl;
                }//end void title

//_________________________________________________________________________________________

                 void menu_2( money *mptr ) //SEARCH menu
                 {

                 string i = "";
                  do{
                  system("cls");

                  cout << "                           Personal             " << endl;
                  cout << "                          Check Register               " << endl;
                  cout << "                                                       " << endl;
                  cout << "                          Search found                    " << endl;
                  cout << "                                                       " << endl;
                  cout << "                  What to do with this transaction?    " << endl;
                  cout << "                                                       " << endl;
                  cout << "                     Type   E: back to main menu \n    " << endl;
                  cout << "                            1. edit transaction  \n    " << endl;
                  cout << "                            2. print transaction     "; getline(cin, i);
                  while(i == ""){
                    i = "x";
                   error(" Please enter a value  "); getline(cin, i);
                  }//end empty

                  switch(toupper(i.at(0))){

                    case 'E':
                    transition();
                    break;

                    case '1':
                    transition();
                    edit( mptr );
                    break;


                    case '2':
                    transition();
                    print_one(mptr);
                    break;

                    default:

                    cout <<" Error: Please enter menu options " <<endl;

                    transition();


                  }//end switch

                  }while(toupper(i.at(0)) != 'E');
                 }//end second menu

//_________________________________________________________________________________________

                 void menu( )
                 {

                  money *mptr = NULL;
                  money *searchptr = NULL;



                 string i = "";

                  do{
                  system("cls");

                  cout << "                          Personal                     " << endl;
                  cout << "                          Check Register               " << endl;
                  cout << "                                                       " << endl;
                  cout << "                           April 23                    " << endl;
                  cout << "                                                       " << endl;
                  cout << "                   -- M A I N   M  E  N  U --          " << endl;
                  cout << "                                                       " << endl;
                  cout << "                     Type   E: exit  \n                " << endl;
                  cout << "                            1: enter payment details \n" << endl;
                  cout << "                            2: Description search    \n" << endl;
                  cout << "                            3: Check # search        \n" << endl;
                  cout << "                            4: print payment details \n" << endl;
                  cout << "                            5: read file             \n" << endl;
                  cout << "                            6: save file             \n" << endl;
                  cout << "                                                             "; getline(cin, i);
                  while(i == ""){
                    i = "x";
                   error(" Please enter a value  "); getline(cin, i);
                  }//end empty


                  switch(toupper(i.at(0))){

                  case '1':
                  transition();
                  mptr = input();
                  break;


                  case '2':
                  transition();
                  searchptr = search_description( mptr );
                  if( searchptr == NULL){
                    cout << "Description search not found \n try again \n returning to main menu " << endl;
                    transition();
                  }
                  else{
                  menu_2(searchptr);
                  }
                  break;


                  case '3':
                  transition();
                  searchptr = search_checknumber(mptr);
                   if( searchptr == NULL ){
                    cout << "Check # not found \n try again \n returning to menu... " <<endl;
                    transition();
                  }
                  else
                  menu_2( searchptr );
                  break;

                  case '4':
                  transition();
                  output(mptr);
                  break;

                  case '5':
                  transition();
                  mptr = readFile();
                  break;

                  case '6':
                  transition();
                  saveFile(mptr);
                  break;

                  case 'E':
                  transition();
                  break;

                  default:
                  error("\n\t\t\t\t Re enter correct menu options and press enter");
                  getline(cin, i);
                  while(i == ""){
                    i = "x";
                   error(" Please enter a value  "); getline(cin, i);
                  }//end empty

                  }// End  switch

              }while(toupper(i.at(0)) != 'E');

                }//end menu

//_________________________________________________________________________________________

            money* readFile(){

            money* a = NULL;
            money* b = NULL;
            money* mptr = NULL;
            char c = 'x';
            ifstream file("transactions.dat");
            cout << "\t Reading data file..." << endl;

            if( c=file.peek() != EOF ){
            a = new money;

            getline(file, a->check);
            getline(file, a->date);
            getline(file, a->desc);
            getline(file, a->str);
            getline(file, a->amount);
            getline(file, a->bal);
            a->next = NULL;
            mptr = a; //starting adr
            }
            else{
            cout << "\t No data file found. Return to main menu..." << endl;
            }

            while( c=file.peek() != EOF ){
            b = new money;
            getline(file, b->check);
            getline(file, b->date);
            getline(file, b->desc);
            getline(file, b->str);
            getline(file, b->amount);
            getline(file, b->bal);
            a->next = b;
            a = a->next;
            }//endwhile

            file.close();
            return mptr;

            }//end readfile

//_________________________________________________________________________________________

            void saveFile(money* mptr){

            ofstream ofile("transactions.dat");
            while( mptr != NULL ){

            ofile << mptr->check << endl;
            ofile << mptr->date << endl;
            ofile << mptr->desc << endl;
            ofile << mptr->str << endl;
            ofile << mptr->amount << endl;
            ofile << mptr->bal << endl;
            mptr = mptr->next;
            }

            ofile.close();
            }//endsavefile

        //_________________________________________________________________________________________

                money* search_description( money *mptr )
                {

                string r = "";
                cout << " \n\n Type description to search for: "; getline(cin, r);

                  for( int i = 0; i < r.length(); i++){
                    r[i]  = toupper( r[i] );
                  }//end capital desc
                 while (  (mptr != NULL) && (mptr->desc != r) ){
                 mptr = mptr->next;
                }//end
                 return mptr;
                }
//_________________________________________________________________________________________

                money* search_checknumber( money *mptr )
                {

                string r = "";
                cout << " \n\n Type check# to search for: "; getline(cin, r);
                while( ( mptr != NULL) && ( mptr->check != r ) ){
                mptr = mptr->next;
                 }//end
                    return mptr;
                }//end search check#

//_________________________________________________________________________________________

                 void transition()
                 {
                  string resp= "x";
                  cout << "                       Press enter to Continue      "; getline(cin, resp);
                  system("cls");
                  }//end void transition
//_________________________________________________________________________________________
                  void error(string msg)
                  {
                  cout << "                       Error!  " << msg << endl;
                  }//end void error
//_________________________________________________________________________________________

                  void exit(){
                  cout << "                $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
                  cout << "                $$              EXIT                     $$" << endl;
                  cout << "                $$                                       $$" << endl;
                  cout << "                $$             thanks!                   $$" << endl;
                  cout << "                $$                                       $$" << endl;
                  cout << "                $$          have a nice day              $$" << endl;
                  cout << "                $$             $   $  $                  $$" << endl;
                  cout << "                $$                                       $$" << endl;
                  cout << "                $$               :D                      $$" << endl;
                  cout << "                $$                                       $$" << endl;
                  cout << "                $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
                  cout << "                                   $$                     "  << endl;
                  cout << "                                   $$                     "  << endl;
                  cout << "                                   $$                     "  << endl;
                  cout << "                                   $$                     "  << endl;
                  cout << "                              $$$$$$$$$$$$                "  << endl;
                  cout << endl;
                  cout << endl;

                    }//end void exit
//_________________________________________________________________________________________

                    money* input()
                    {

                        money *mptr = NULL;
                        money *a = NULL;
                        money *b = NULL;

                        string r = "";
                        string cap_desc = "";

                  cout << "                               Personal                 " << endl;
                  cout << "                            Check Register   \n         " << endl;
                  cout << "                          Enter transaction? (y/n) \n   "; getline(cin, r);
                  while(r == ""){
                    r = "x";
                   error(" Please enter a value:  "); getline(cin, r);
                  }//end empty
                  while(toupper(r.at(0)) != 'Y' && toupper(r.at(0)) != 'N' ){
                    error("Re enter correct menu options and press enter"); getline(cin, r);
                  while(r == ""){
                    r = "x";
                   error(" Please enter a value:  "); getline(cin, r);
                  }//end empty
                  }//end not y or n

                  if(toupper(r.at(0)) == 'N'){

                cout << "                   Returning to menu... " << endl;
                transition();
                 exit();
                  }

                  if(toupper(r.at(0)) == 'Y'){

                    mptr = new money;

                  cout << "                          Entering Payment Details    " << endl;
                  cout << "                                                       " << endl;
                  cout << "                          Enter check number: "; getline(cin, mptr->check);
                    while(mptr->check.empty()){
                     error(" Please enter a value  "); getline(cin, mptr->check);
                  }//end empty
                  cout << "                                                       " << endl;
                  cout << "                          Enter the date             "; getline(cin, mptr->date);
                  cout << "                                                       " << endl;
                  cout << "                          Describe transaction:  "; getline(cin, mptr->desc); //caps
                   while(mptr->desc.empty()){
                     error(" Please enter a value  "); getline(cin, mptr->desc);
                  }//end empty
                  cap_desc = mptr->desc;
                  for( int i = 0; i < cap_desc.length(); i++){
                    cap_desc[i]  = toupper( cap_desc[i] );
                  }//end capital desc
                  mptr->desc = cap_desc;

                  cout << "                                                       " << endl;
                  cout << "                          Enter check balance $: "; getline(cin, mptr->bal);
                    while( mptr->bal.empty()){
                     error(" Please enter a value  "); getline(cin, mptr->bal);
                  }//end empty

                  while ( mptr->bal.at(0) < '0' || mptr->bal.at(0) > '9' ){  //check letter or number obj
                     error(" Please enter a balance 0 or greater   ");getline(cin, mptr->bal);
                     while( mptr->bal.empty()){
                     error(" Please enter a value  "); getline(cin, mptr->bal);
                  }//end empty
                  }//end balance error

                  cout << "                          deposit(D) or withdraw(W)? "; getline(cin, mptr->str);
                  while( mptr->str.empty()){
                   error(" Please enter a value  "); getline(cin, mptr->str);
                  }//end empty


                    while (! ( toupper( mptr->str.at(0) ) == 'D' || toupper( mptr->str.at(0) )== 'W' )){

                        error("Re enter menu options:  "); getline(cin, mptr->str);
                        while(mptr->str.empty()){
                        error(" Please enter a value  "); getline(cin, mptr->str);
                  }//end empty
                     }//end deposit/withdraw error


                    if ( toupper( mptr->str.at(0) ) == 'D'){

                  cout << "                          Enter deposit amount:  $ "; getline(cin, mptr->amount);
                  while(mptr->amount.empty()){
                     error(" Please enter a value  "); getline(cin, mptr->amount);
                  }//end empty

                    }//end deposit input

                     if ( toupper( mptr->str.at(0) ) == 'W'  ){

                  cout << "                          Enter withdraw amount:  $ "; getline(cin, mptr->amount);
                  while(mptr->amount.empty()){
                     error(" Please enter a value  "); getline(cin, mptr->amount);
                  }//end empty

                     }//end withdraw input


                  while ( mptr->amount.at(0) < '0' || mptr->amount.at(0) > '9'){

                    error("Please enter a number:  ");getline(cin, mptr->amount);
                    while( mptr->amount.empty()){
                     error(" Please enter a value  "); getline(cin, mptr->amount);
                  }//end empty


                  }//end price error

                  mptr->next = NULL;
                  a = mptr;
                  transition();

                  cout << "                          Enter another transaction? (y/n): "; getline(cin, r);
                  while(r == ""){
                    r = "x";
                   error(" Please enter a value:  "); getline(cin, r);
                  }//end empty
                  while(toupper(r.at(0)) != 'Y' && toupper(r.at(0)) != 'N' ){
                    error("Re enter correct menu options and press enter"); getline(cin, r);
                  while(r == ""){
                    r = "x";
                   error(" Please enter a value:  "); getline(cin, r);
                  }//end empty
                  }//end not y or n
                  }//end pointer if


                  while(toupper(r.at(0)) == 'Y'){

                   b = new money;

                  cout << "                          Entering Payment Details    " << endl;
                  cout << "                                                       " << endl;
                  cout << "                          Enter check number: "; getline(cin, b->check);
                    while(b->check.empty()){
                     error(" Please enter a value  "); getline(cin, b->check);
                  }//end empty
                  cout << "                                                       " << endl;
                  cout << "                          Enter the date             "; getline(cin, b->date);
                  cout << "                                                       " << endl;
                  cout << "                          Describe transaction:  "; getline(cin, b->desc); //caps
                   while( b->desc.empty()){
                     error(" Please enter a value  "); getline(cin, b->desc);
                  }//end empty
                  cap_desc = b->desc;
                  for( int i = 0; i < cap_desc.length(); i++){
                    cap_desc[i]  = toupper( cap_desc[i] );
                  }//end capital desc
                  b->desc = cap_desc;

                  cout << "                                                       " << endl;
                  cout << "                          Enter check balance $: "; getline(cin, b->bal);
                    while( b->bal.empty()){
                     error(" Please enter a value  "); getline(cin, b->bal);
                  }//end empty

                  while ( b->bal.at(0) < '0' || b->bal.at(0) > '9' ){  //check letter or number obj
                     error(" Please enter a balance 0 or greater   ");getline(cin, b->bal);
                     while( b->bal.empty()){
                     error(" Please enter a value  "); getline(cin, b->bal);
                  }//end empty
                  }//end balance error

                  cout << "                          deposit(D) or withdraw(W)? "; getline(cin, b->str);
                  while( b->str.empty()){
                   error(" Please enter a value  "); getline(cin, b->str);
                  }//end empty


                    while (! ( toupper( b->str.at(0) ) == 'D' || toupper( b->str.at(0) )== 'W' )){

                        error("Re enter menu options:  "); getline(cin, b->str);
                        while( b->str.empty()){
                        error(" Please enter a value  "); getline(cin, b->str);
                  }//end empty
                     }//end deposit/withdraw error


                    if ( toupper( b->str.at(0) ) == 'D'){

                  cout << "                          Enter deposit amount:  $ "; getline(cin, b->amount);
                  while( b->amount.empty()){
                     error(" Please enter a value  "); getline(cin, b->amount);
                  }//end empty

                    }//end deposit input

                     if ( toupper( b->str.at(0) ) == 'W'  ){

                  cout << "                          Enter withdraw amount:  $ "; getline(cin, b->amount);
                  while( b->amount.empty()){
                     error(" Please enter a value  "); getline(cin, b->amount);
                  }//end empty
                     }//end withdraw input


                  while ( b->amount.at(0) < '0' || b->amount.at(0) > '9'){

                    error("Please enter a number:  ");getline(cin, b->amount);
                    while( b->amount.empty()){
                     error(" Please enter a value  "); getline(cin, b->amount);
                  }//end empty
                  }//end price error

                    b->next = NULL;
                    a->next = b;
                    a = a->next; //a connects 2 structures
                    transition();

                    cout << "                        Enter another transaction? (y/n): "; getline(cin, r);

                   while(r == ""){
                    r = "x";
                   error(" Please enter a value:  "); getline(cin, r);
                    }//end empty
                   while(toupper(r.at(0)) != 'Y' && toupper(r.at(0)) != 'N' ){
                    error("Re enter correct menu options and press enter"); getline(cin, r);
                   while(r == ""){
                    r = "x";
                   error(" Please enter a value:  "); getline(cin, r);
                  }//end empty
                  }//end not y or n
                  }//end  while

                    transition();
                    return mptr;
                  }//end money input
//_________________________________________________________________________________________


                 void edit( money *mptr )
                 {
                      string i = "x";
                      do{
                  system("cls");

                  cout << "                                                      " << endl;
                  cout << "                         CURRENT VALUES:              " << endl;
                  cout << "                Check's balance: $"<< mptr->bal  << endl;
                  cout << "                1. Check number: " << mptr->check << "       3. Transaction Description:  " << mptr->desc << endl;
                  cout << "                2. Date: " << mptr->date << "                4. Transaction amount: $" << mptr->amount << endl;
                  cout << "                                                     5. Deposit or withdraw: " << mptr->str << endl;

                  cout << "                                              " << endl;
                  cout << "                          EDIT SCREEN         " << endl;
                  cout << "                                              " << endl;
                  cout << "                 Press 1: to change check number " << endl;
                  cout << "                                              " << endl;
                  cout << "                       2: date                " << endl;
                  cout << "                                              " << endl;
                  cout << "                       3: transaction description    " << endl;
                  cout << "                                              " << endl;
                  cout << "                       4: transaction amount  " << endl;
                  cout << "                                              " << endl;
                  cout << "                       5: deposit or withdraw  " << endl;
                  cout << "                                              " << endl;
                  cout << "                       E: stop making changes "; getline(cin, i);
                  while(i == ""){
                    error("Enter a value: \n"); getline(cin, i);
                  }

                  switch(toupper(i.at(0))){
                  case '1':
                    cout << "                Enter new check number "; getline(cin, mptr->check);
                    while(mptr->check.empty()){
                     error(" Please enter a value  "); getline(cin, mptr->check);
                  }//end empty
                    break;

                  case '2':
                    cout << "                Enter new date  "; getline(cin, mptr->date);
                    break;

                  case '3':
                    cout << "                Enter new description "; getline(cin, mptr->desc);
                    while(mptr->desc.empty()){
                     error(" Please enter a value  "); getline(cin, mptr->desc);
                  }//end empty
                    break;

                  case '4':
                    cout << "                Enter new transaction amount "; getline(cin, mptr->amount);
                    while(mptr->amount.empty()){
                    error(  "Please enter a value "); getline(cin, mptr->amount);
                  }//end empty
                     while ( mptr->amount.at(0) < '0' || mptr->amount.at(0) > '9'){

                    error("Please enter a number:  ");getline(cin, mptr->amount);
                    while(mptr->amount.empty()){
                    error(  "Please enter a value "); getline(cin, mptr->amount);
                  }//end empty
                  }//end price error
                    break;

                  case '5':
                    cout << "                Deposit or withdraw ? "; getline(cin, mptr->str);
                     while(mptr->str.empty()){
                    error(  "Please enter a value "); getline(cin, mptr->str);
                  }//end empty
                     while (! (  toupper(mptr->str.at(0) ) == 'D' || toupper( mptr->str.at(0) )== 'W' )){
                        error("Re enter menu options: ");getline(cin, mptr->str);
                }//end deposit/withdraw error

                  case 'E':
                  transition();
                  break;


                  default:
                  error("Re enter menu options, then press enter: ");getline(cin, i);
                  while(i == ""){
                      i="x";
                    error(  "Please enter a value: "); getline(cin,i);
                  }//end empty

                  } //end switch

                 }while(toupper(i.at(0)) != 'E');

                  }//end money edit
//_________________________________________________________________________________________

               void output(money *aptr)
               {

                   money* mptr = aptr;
                   double ending_balance = 0; double check_total = 0;



                  cout << "                          Personal        " << endl;
                  cout << "                         Check Register         " << endl;
                  cout << "                                                " << endl;
                  cout << "                          PAYMENT DETAILS :       "  << endl;


                  while( mptr != NULL){
                  cout << "                                                " << endl;
                  cout << setw(6) << "   Check number: " << mptr->check
                  << setw(6) << "   Date: " << mptr->date
                  << setw(6) << "   Transaction Description:  " << mptr->desc << endl;
                  cout << "                                  " << endl;


                  if ( toupper ( mptr->str.at(0) ) == 'D' ){

                  check_total = atof(mptr->bal.data())+ atof(mptr->amount.data()); //leftover

                  cout << setw(6) << "  Check balance: $"<< mptr->bal
                       << setw(6) << ". Deposited $" << mptr->amount
                       << setw(6) << ", now Check balance is  $ " << check_total << endl;
                       cout << "-------------------------------------------------------------" << endl;
                  cout << "                                                 " << endl;
                    ending_balance += check_total;
                 }//end  deposit

                  if ( toupper( mptr->str.at(0) ) == 'W'){

                  check_total = atof( mptr->bal.data())- atof( mptr->amount.data());

                  cout << setw(6) << "  Check's balance: $"<< mptr->bal
                       << setw(6) << ". Withdrew $" << mptr->amount
                       << setw(6) << ", now Check balance is  $ " << check_total << endl;
                       cout << "-------------------------------------------------------------" << endl;
                  cout << "                                  " << endl;
                    ending_balance += check_total;

                  }//end  withdraw
                  mptr = mptr->next;
                    }//end while

                  string r= "";
                  cout << "-------------------------------------------------------------" << endl;
                  cout << " Net balance of all checks is $" << ending_balance << endl;
                  cout << "   \n File print this screen (external .prn file) ? (Y/N)"; getline(cin, r);
                  while(r == ""){
                    error("Re enter menu options and press enter: "); getline(cin, r);
                  }

                  switch( toupper(r.at(0)) ){

                  case 'Y':
                  print( aptr ); //mptr is incremented to null. use aptr
                  break;

                  case 'N':
                  transition();
                  exit();
                  break;

                  default:
                  error("Re enter menu options and press enter: ");getline(cin, r);

                  }//end switch
                  }//end output
//_________________________________________________________________________________________

                  void print( money *mptr )
                  {

                  ofstream printer;
                  printer.open("alltransactions.prn");
                  system("cls");
                  double ending_balance = 0; double check_total = 0;

                  printer << "                          Personal        " << endl;
                  printer << "                         Check Register         " << endl;
                  printer << "                                                " << endl;
                  printer << "                          PAYMENT DETAILS :       "  << endl;

                    while( mptr != NULL ){
                  printer << "                                                " << endl;
                  printer << setw(6) << "   Check number: " << mptr->check
                  << setw(6) << "   Date: " << mptr->date
                  << setw(6) << "   Transaction Description:  " << mptr->desc << endl;
                  printer << "                                  " << endl;

                  if ( toupper( mptr->str.at(0) ) == 'D' ){

                        check_total = atof( mptr->bal.data())+ atof( mptr->amount.data()); //leftover

                  printer << setw(6) << "  Check's balance: $"<< mptr->bal
                          << setw(6) << ". Deposited $" << mptr->amount
                          << setw(6) << ", now Check balance is  $ " << check_total << endl;
                          cout << "-------------------------------------------------------------" << endl;
                  printer << "                                                 " << endl;
                  ending_balance += check_total;
                 }//end  deposit

                  if ( toupper( mptr->str.at(0) ) == 'W'){

                        check_total = atof( mptr->bal.data())- atof( mptr->amount.data());

                  printer << setw(6) <<"  Check's balance: $"<< mptr->bal
                  << setw(6) <<". Withdrew $" << mptr->amount
                  << setw(6) << ", now Check balance is  $ " << check_total << endl;
                  cout << "-------------------------------------------------------------" << endl;
                   printer << "                                  " << endl;
                  ending_balance += check_total;

                  }//end  withdraw

                  mptr = mptr->next;
                    }//end while

                  printer << "-------------------------------------------------------------" << endl;
                  printer << " Net balance of all checks is $" << ending_balance << endl;


                  printer.close();

                    cout << "                             Print completed " << endl;
                    exit();
                  }//end print
//_________________________________________________________________________________________


                   void print_one(money *mptr)
                   {

                  ofstream printer;
                  printer.open("onetransaction.prn");
                  system("cls");


                  printer << "                          Personal        " << endl;
                  printer << "                         Check Register         " << endl;
                  printer << "                                                " << endl;
                  printer << "                          PAYMENT DETAILS :       "  << endl;


                  printer << "                                                " << endl;
                  printer << setw(6) << "   Check number: " << mptr->check
                  << setw(6) << "   Date: " << mptr->date
                  << setw(6) << "   Transaction Description:  " << mptr->desc << endl;
                  printer << "                                  " << endl;

                  if ( toupper( mptr->str.at(0) )== 'D'  ){

                  printer << setw(6) << "  Check's balance: $"<< mptr->bal
                          << setw(6) << ". Deposited $" << mptr->amount
                          << setw(6) << ", now Check balance is  $ " << atof( mptr->bal.data())+ atof( mptr->amount.data()) << endl;
                          printer << "-------------------------------------------------------------" << endl;
                  printer << "                                                 " << endl;

                 }//end  deposit

                  if ( toupper( mptr->str.at(0) ) == 'W' ){

                  printer << setw(6) <<"  Check's balance: $"<< mptr->bal
                  << setw(6) <<". Withdrew $" << mptr->amount
                  << setw(6) << ", now Check balance is  $ " << atof( mptr->bal.data())- atof( mptr->amount.data()) << endl;
                  printer << "-------------------------------------------------------------" << endl;
                   printer << "                                  " << endl;

                  }//end  withdraw


                  printer << "-------------------------------------------------------------" << endl;
                  mptr = mptr->next;
                  printer.close();

                    cout << "                             Print completed " << endl;


                    exit();

                  }//end print_one



