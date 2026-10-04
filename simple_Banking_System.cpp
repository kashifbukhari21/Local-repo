#include <iostream>
using namespace std;

string name;                            //varable decleration
string dob;
string cnic;
string phone;
string password;
string loginpass;
string logincnic;
string accountrank;
double charges;
double appliedcharges;
double balance = 0;
double deposit_amount;
double withdraw_amount;
bool accountcreated = false;
bool accountlogin = false;
int age;

bool Create()                                          // Account Creation Module
{
	string confirmPassword;

    cout<<"===== Account Creation ====="<<endl;

    cout<<"Enter Your Name: ";
    cin>>name;

    cout<<"Enter Date of Birth: ";
    cin>>dob;

    cout<<"Enter Your Age: ";
    cin>>age;

    cout<<"Enter CNIC Number: ";
    cin>>cnic;

    cout<<"Enter Phone Number: ";
    cin>>phone;
    
    cout<<"Enter Your Account Rank (Basic, Premium, Elite): ";
    cin>>accountrank;

    cout<<"Create Password: ";
    cin>>password;

    cout<<"Re-enter Password: ";
    cin>>confirmPassword;

    if(password == confirmPassword)
        {
            cout<<"\nAccount Created Successfully!"<<endl;

            return true;
        }
    else
        {
            cout<<"\nError: Passwords do not match!"<<endl;

            return false;	
		}
}


			
bool Login()                                                 //login Module
{
    cout<<"=========Login========="<<endl;
	
	cout<<"Enter CNIC Number: ";
	cin>>logincnic;
	
	cout<<"Enter Password: ";
	cin>>loginpass;
	
	if(logincnic == cnic && loginpass == password)	
	    {
	    	cout<<"You are Successfully Login"<<endl;
	     	return true;
		}
	else
	    {
	    	cout<<"Oops! Try Again"<<endl;
	     	return false;
		}	 
}



double deposit()                                             // Deposit Module
{
	double amount;
	
	cout<<"Enter amount To Deposit: ";
	cin>>amount;
	
	cout<<endl;
	
	if(amount > 0)
	     {
	     	cout<<"Your Amount is successfully deposit."<<endl;
	     	return amount;
		 }
	
	else
	     {
	     	cout<<"Invalid Amount! Please Enter Amount Greater then 0 "<<endl;
	     	
	     	return 0;
		 }	 
}




double withdraw()                                            // Withdraw Module
{
	double amount;
	
	cout<<"Enter Amount To Withdraw: ";
	cin>>amount;
	
	cout<<endl;
	
	if(amount > 0)
	       {
	       	  if(amount <= balance)
	       	      {
	       	      	cout<<"Withdrawal Successful"<<endl;
	       	      	
	       	      	return amount;
				  }
			  else
			      {
			      	cout<<"Insufficient Balance!"<<endl;
			      	
			      	return 0;
				  }	  
		   }
	else
	       {
	       	cout<<"Invalid Amount! Please enter amount greater then 0 "<<endl;
	       	
	       	return 0;
		   }	   
}



double rank(string x)                                         // Apply Charges According to Rank Module
{
	if(x == "Basic" )
	    {
	       return 0.050;	
		}
	
	else if(x == "Premium")	
	    {
	    	return 0.025; 
		}
	else if(x == "Elite")
	    {
	    	return 0.015;
		}
	else
	    {
	    	return 0;
		}		
}


void report ()                                                // Report Module
{
	cout<<"Here is Your Final Report"<<endl;
	
	cout<<"Name: "<<name<<endl;
	
	cout<<"CNIC: "<<cnic<<endl;
	
	cout<<"Account Rank: "<<accountrank<<endl;
	
	cout<<"Total Balance: "<<balance<<endl;
	
	cout<<"withdraw Amount: "<<withdraw_amount<<endl;
	
	cout<<"Deposit Amount: "<<deposit_amount<<endl;
	
	cout<<"Applied Charges: "<<appliedcharges<<endl;
	
}
		   
int main()                                                    //Main Menu Module
{
	char Repeat;
	do
	{
	
	 char Again;  
	 int choice, choice_2;
	 do
	  {
	  
    	cout<<"welcome to Bank"<<endl;
	
     	cout<<"select One operation from the following"<<endl;
	
    	cout<<"1. create New account"<<endl;
	
      	cout<<"2. Login to an Account"<<endl;
	
    	cin>>choice;
	
    	switch(choice)
		         {
				 
		         	case 1:
		                 {
		                 	while (accountcreated == false)
		                 	     {
								      accountcreated = Create();
								      
								      cout<<"After Creating an Account You Must need to login"<<endl;
		                         }
		                 	break;
						 }
					case 2:
						 {
						 	if(accountcreated == true)
						 	    {
						 	    	while (accountlogin == false)
						 	    	     {
										     accountlogin = Login();
								         }
										
						 	    }
						 	else
							    {
							    	cout<<"Create Account First"<<endl;
								}
								    
						 	break;
						 }
					default:
					     {
					     	cout<<"Accidentally You Selected Wrong Option"<<endl;
					     	
					     	break;
						 }	 
			      }
		
		cout<<"if your Account is successfully Created then login first "<<endl;
			      
		cout<<"Do you want to repeat all steps again? (Y/N): ";
		cin>>Again;	      
      }while(Again == 'Y' || Again == 'y');
      
      
	 if(accountcreated == true && accountlogin == true )
	     {
	     	char again;
	     	
	     	charges = rank(accountrank);                 // Calculate charges  
	     	
	     	
	     do
		   {
			   	
	     	cout<<"what do you want to do? (select with respect to curresponding numbers) "<<endl;
	     	
	     	cout<<"1. Deposite Money"<<endl;
	     	
	     	cout<<"2. Withdraw Money"<<endl;
	     	
	     	cout<<"3. Balance Check"<<endl;
	     	
	     	cin>>choice_2;
	     	
	     	switch(choice_2)
	     	               {
	     	               	   case 1:
	     	               	   	     {
	     	               	   	     	char repeat;
	     	               	   	     	
	     	               	   	     	do
	     	               	   	     	  {
	     	               	   	     	
	     	               	   	     	     deposit_amount = deposit();
	     	               	   	     	
	     	               	   	     	     balance = balance + deposit_amount;
	     	               	   	     	     
	     	               	   	     	     cout<<"Do You Want to Deposit again(Y/N): ";
	     	               	   	     	     cin>>repeat;
	     	               	   	     	     
	     	               	   	          }while (repeat == 'Y' || repeat == 'y');
	     	               	   	     	 
	     	               	   	     	 break;
									 }
								case 2:
								     {
								     	char repeat;
								     	
								     	do
								     	   {
								     	
								     	       withdraw_amount = withdraw();
								     	
								     	       appliedcharges = withdraw_amount * charges;
								     	
								     	       balance = balance - (withdraw_amount + appliedcharges);
								     	       
								     	       cout<<"Do you want to Withdraw Again(Y/N): ";
								     	       cin>>repeat;
								     	       
								           }while (repeat == 'Y' || repeat == 'y');
								           
								     	break;
									 }
								case 3:
								     {
								     	char repeat;
								     	
								     	do
								     	   {
											
								     	       cout<<"Your Balance is: "<<balance<<endl;
								     	
								               cout<<"Do you want to Check Balance Again(Y/N): ";
								     	       cin>>repeat;
								     	       
								           }while (repeat =='Y' || repeat == 'y');
								     	
								     	break;
									 }
								default:
								     {
								     	cout<<"Accidentally You Selected Wrong Option"<<endl;
								     	
								     	break;
									 }	 	 
						   }
			cout<<"Do you want to repeat all the steps again? (Y/N): ";
			cin>>again;
			cout<<endl;
						   
           }while ((choice_2 != 1 && choice_2 != 2 && choice_2 != 3) || (again == 'Y' || again == 'y'));
           
           cout<<"Here is your Final Report"<<endl;
           
           report();
           
           
		 }
     else
         {
         	cout<<"Please Enter valid information"<<endl;
		 }
		 
	 cout<<"Do you Repeat all steps againfrom start ";
	 cin>>Repeat;	 
	 
    }while (Repeat == 'Y' || Repeat == 'y');
    
    return 0;
}