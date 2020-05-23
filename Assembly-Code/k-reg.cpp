#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
int main()
{
	  ifstream f("op-basic-block.txt");
	  //int reserve[6]={1,26,27,29,30,31};
	  string line,rd,val,lab,line2,l;
	  int pos1,pos2,en,pos3,pos4,reg;
	  
	  int disp=0;
	  int index=0;
	  int arr[32]={0};
	  int n = sizeof(arr)/sizeof(arr[0]);
	  auto itr=find(arr,arr+n,0);
	  int first_line=0;
	  while(!f.eof()){
	  getline(f,line);
	  if (first_line==0)
	  {
		cout<<".text"<<endl;
		first_line = 1;
	  }

	  if(line.find("goto")==0)
	  {
		//cout << "---------WTF-----------------"<<endl; 
	    	pos1=line.find("(");
		pos2=line.find(")");
		//cout<< "pos1="<<pos1<<",pos2="<<pos2<<endl;
		rd=line.substr(pos1+1,pos2-pos1-1);
		cout<< "J "<<rd <<endl;
	  }
	if(line.find("if")>=0 && line.find("if")<1000)
  	{
		//cout<<"--------------iF-----------------------"<<endl;
		if(line.find(">=")>=0 && line.find(">=")<1000)
		{
			pos1=line.find("if");
			pos2=line.find(">=");
			rd=line.substr(pos1+4,pos2-pos1-3);
			en=line.find("goto");
			val=line.substr(pos2+2,en-pos2-3);
			pos3=line.find("(");
			pos4=line.find(")");
			lab=line.substr(pos3+1,pos4-pos3-1);
			int ird=stoi(rd);
			int ival=stoi(val);
			itr=find(arr,arr+n,ird);
			if (itr==end(arr))
			{
				arr[index++]=ird;ird=index-1;
			}
			else
			{
				ird=distance(arr,itr);
			}
			itr=find(arr,arr+n,ival);
			if (itr==end(arr))
			{
				arr[index++]=ival; ival=index-1;
			}
			else
			{
				ival=distance(arr,itr);
			}
			
			cout << "BGE $"<<ird<<", $"<<ival<<", "<<lab<<endl;
			//cout<<"bge "<<rd<<" 50"<<endl;
			//cout << "greater than "<<rd <<endl;
		}
		else if(line.find("!=")>=0 && line.find("!=")<1000)
		{
			pos1=line.find("if");
			pos2=line.find("!=");
			rd=line.substr(pos1+4,pos2-pos1-3);
			en=line.find("goto");
			val=line.substr(pos2+2,en-pos2-3);
			pos3=line.find("(");
			pos4=line.find(")");
			lab=line.substr(pos3+1,pos4-pos3-1);
			int ird=stoi(rd);
			int ival=stoi(val);
			itr=find(arr,arr+n,ird);
			if (itr==end(arr))
			{
				arr[index++]=ird;ird=index-1;
			}
			else
			{
				ird=distance(arr,itr);
			}
			itr=find(arr,arr+n,ival);
			if (itr==end(arr))
			{
				arr[index++]=ival; ival=index-1;
			}
			else
			{
				ival=distance(arr,itr);
			}
			
			
			cout << "BNE $"<<ird<<", $"<<ival<<", "<<lab<<endl;
			//cout << "bne "<<rd << " 0"<<endl;
		}
		else if(line.find(">")>=0 && line.find(">")<1000)
		{
			pos1=line.find("if");
			pos2=line.find(">");
			rd=line.substr(pos1+4,pos2-pos1-4);
			en=line.find("goto");
			val=line.substr(pos2+2,en-pos2-3);
			pos3=line.find("(");
			pos4=line.find(")");
			lab=line.substr(pos3+1,pos4-pos3-1);
			int ird=stoi(rd);
			int ival=stoi(val);
			itr=find(arr,arr+n,ird);
			if (itr==end(arr))
			{
				arr[index++]=ird;ird=index-1;
			}
			else
			{
				ird=distance(arr,itr);
			}
			itr=find(arr,arr+n,ival);
			if (itr==end(arr))
			{
				arr[index++]=ival; ival=index-1;
			}
			else
			{
				ival=distance(arr,itr);
			}
			
			
			cout << "BGT $"<<ird<<", $"<<ival<<", "<<lab<<endl;
		}
		else if(line.find("<")>=0 && line.find("<")<1000)
		{
			pos1=line.find("if");
			pos2=line.find("<");
			rd=line.substr(pos1+4,pos2-pos1-4);
			en=line.find("goto");
			val=line.substr(pos2+2,en-pos2-3);
			pos3=line.find("(");
			pos4=line.find(")");
			lab=line.substr(pos3+1,pos4-pos3-1);
			int ird=stoi(rd);
			int ival=stoi(val);
			itr=find(arr,arr+n,ird);
			if (itr==end(arr))
			{
				arr[index++]=ird;ird=index-1;
			}
			else
			{
				ird=distance(arr,itr);
			}
			itr=find(arr,arr+n,ival);
			if (itr==end(arr))
			{
				arr[index++]=ival; ival=index-1;
			}
			else
			{
				ival=distance(arr,itr);
			}
			
			
			cout << "BLT $"<<ird<<", $"<<ival<<", "<<lab<<endl;
		}
		else if(line.find("==")>=0 && line.find("==")<1000)
		{
			pos1=line.find("if");
			pos2=line.find("==");
			rd=line.substr(pos1+4,pos2-pos1-4);
			en=line.find("goto");
			val=line.substr(pos2+3,en-pos2-3);
			pos3=line.find("(");
			pos4=line.find(")");
			lab=line.substr(pos3+1,pos4-pos3-1);
			int ird=stoi(rd);
			int ival=stoi(val);
			itr=find(arr,arr+n,ird);
			if (itr==end(arr))
			{
				arr[index++]=ird;ird=index-1;
			}
			else
			{
				ird=distance(arr,itr);
			}
			itr=find(arr,arr+n,ival);
			if (itr==end(arr))
			{
				arr[index++]=ival; ival=index-1;
			}
			else
			{
				ival=distance(arr,itr);
			}
			
			
			cout << "BEQ $"<<ird<<", $"<<ival<<", "<<lab<<endl;
		}
  	}

	if(line.find("Basic_block") >= 0 && line.find("Basic_block")<1000)
	{
        	index=0;
  	}
	else if(line.find("label")==0)
	{
			pos1=line.find("label");
			rd=line.substr(pos1+6);
			
			cout<<rd<<":"<<endl;

			int pos=0;
			getline(f,line);
			
			while(!f.eof())
			{
				if (line.find("Basic_block")==0)
				{
					index=0; break;
				}
				if(line.find("label")==0)
				{
					pos1=line.find("label");
					rd=line.substr(pos1+6);
					pos3=line.find("label"+rd);
					rd=line.substr(pos1,pos1+8);
					cout<<rd<<":"<<endl;
				}


				if(line.find("goto")==0)
				{
				    	pos1=line.find("(");
					pos2=line.find(")");
					//finding the label name: rd
					rd=line.substr(pos1+1,pos2-pos1-1);
					cout<< "J "<<rd <<endl;
				  }
				if(line.find("if")>=0 && line.find("if")<1000)
				  {
					//cout<<"--------------iF-----------------------"<<endl;
					if(line.find(">=")>=0 && line.find(">=")<1000)
					{
						pos1=line.find("if");
						pos2=line.find(">=");
						rd=line.substr(pos1+4,pos2-pos1-4);
						en=line.find("goto");
						val=line.substr(pos2+2,en-pos2-3);
						pos3=line.find("(");
						pos4=line.find(")");
						lab=line.substr(pos3+1,pos4-pos3-1);
						int ird=stoi(rd);
						int ival=stoi(val);
						itr=find(arr,arr+n,ird);
						if (itr==end(arr))
						{
							arr[index++]=ird;ird=index-1;
						}
						else
						{
							ird=distance(arr,itr);
						}
						itr=find(arr,arr+n,ival);
						if (itr==end(arr))
						{
							arr[index++]=ival; ival=index-1;
						}
						else
						{
							ival=distance(arr,itr);
						}
						
						
						cout << "BGE $"<<ird<<", $"<<ival<<", "<<lab<<endl;
					
					}
					else if(line.find("!=")>=0 && line.find("!=")<1000)
					{
						pos1=line.find("if");
						pos2=line.find("!=");
						rd=line.substr(pos1+4,pos2-pos1-4);
						en=line.find("goto");
						val=line.substr(pos2+3,en-pos2-3);
						pos3=line.find("(");
						pos4=line.find(")");
						lab=line.substr(pos3+1,pos4-pos3-1);
						int ird=stoi(rd);
						int ival=stoi(val);
						itr=find(arr,arr+n,ird);
						if (itr==end(arr))
						{
							arr[index++]=ird;ird=index-1;
						}
						else
						{
							ird=distance(arr,itr);
						}
						itr=find(arr,arr+n,ival);
						if (itr==end(arr))
						{
							arr[index++]=ival; ival=index-1;
						}
						else
						{
							ival=distance(arr,itr);
						}
						cout << "BNE $"<<ird<<", $"<<ival<<", "<<lab<<endl;
						
					}
					else if(line.find(">")>=0 && line.find(">")<1000)
					{
						pos1=line.find("if");
						pos2=line.find(">");
						rd=line.substr(pos1+4,pos2-pos1-4);
						en=line.find("goto");
						val=line.substr(pos2+2,en-pos2-3);
						pos3=line.find("(");
						pos4=line.find(")");
						lab=line.substr(pos3+1,pos4-pos3-1);
						int ird=stoi(rd);
						int ival=stoi(val);
						itr=find(arr,arr+n,ird);
						if (itr==end(arr))
						{
							arr[index++]=ird;ird=index-1;
						}
						else
						{
							ird=distance(arr,itr);
						}
						itr=find(arr,arr+n,ival);
						if (itr==end(arr))
						{
							arr[index++]=ival; ival=index-1;
						}
						else
						{
							ival=distance(arr,itr);
						}
						cout << "BGT $"<<ird<<", $"<<ival<<", "<<lab<<endl;
					}
					else if(line.find("<")>=0 && line.find("<")<1000)
					{
						pos1=line.find("if");
						pos2=line.find("<");
						rd=line.substr(pos1+4,pos2-pos1-4);
						en=line.find("goto");
						val=line.substr(pos2+2,en-pos2-3);
						pos3=line.find("(");
						pos4=line.find(")");
						lab=line.substr(pos3+1,pos4-pos3-1);
						int ird=stoi(rd);
						int ival=stoi(val);
						itr=find(arr,arr+n,ird);
						if (itr==end(arr))
						{
							arr[index++]=ird;ird=index-1;
						}
						else
						{
							ird=distance(arr,itr);
						}
						itr=find(arr,arr+n,ival);
						if (itr==end(arr))
						{
							arr[index++]=ival; ival=index-1;
						}
						else
						{
							ival=distance(arr,itr);
						}
						cout << "BLT $"<<ird<<", $"<<ival<<", "<<lab<<endl;
					}
					else if(line.find("==")>=0 && line.find("==")<1000)
					{
						pos1=line.find("if");
						pos2=line.find("==");
						rd=line.substr(pos1+4,pos2-pos1-4);
						en=line.find("goto");
						val=line.substr(pos2+3,en-pos2-3);
						pos3=line.find("(");
						pos4=line.find(")");
						lab=line.substr(pos3+1,pos4-pos3-1);
						int ird=stoi(rd);
						int ival=stoi(val);
						itr=find(arr,arr+n,ird);
						if (itr==end(arr))
						{
							arr[index++]=ird;ird=index-1;
						}
						else
						{
							ird=distance(arr,itr);
						}
						itr=find(arr,arr+n,ival);
						if (itr==end(arr))
						{
							arr[index++]=ival; ival=index-1;
						}
						else
						{
							ival=distance(arr,itr);
						}
						cout << "BEQ $"<<ird<<", $"<<ival<<", "<<lab<<endl;
					}
				  }




				// GENERAL OPERATIONS
			string subs,r1,r2;
			int eq=line.find("="),i;
			int dbeq=line.find("==");
			int neq=line.find("!=");
			rd=line.substr(0,eq);
			line=line.substr(eq+1);
				
   
			    if((line.find("+")>0 && line.find("+")<1000) || (line.find("-")>0 && line.find("-")<1000) || (line.find("*")>0 && line.find("*")<1000)||(line.find("%")>0 && line.find("%")<1000) || (line.find("/")>0 && line.find("/")<1000))
			    {
			      if(line.find("+")>0 && line.find("+")<1000)
			      {
				int plus=line.find("+");
				r1=line.substr(0,plus); //rhs first
				
				line=line.substr(plus+1); //rhs second
				//cout<<"[[[[[[[[[[ RHS ARGS ]]]]]]]]]"<<line.substr(2)<<endl;
			     	//first: checking if they are already regs
				int rhs1 = r1.find("t");
				int rhs2 = line.find("t"); 
				if (rhs1!=-1 && rhs2!=-1 && rd.substr(0,1).compare("t")==0) 
				{
					int rr1=stoi(r1.substr(2));
					int rr2=stoi(line.substr(2));
					int ll1=stoi(rd.substr(1,eq-1));
					
					itr=find(arr,arr+n,rr1);
					if (itr==end(arr))
					{
						arr[index++]=rr1;rr1=index-1;
					}
					else
					{
						rr1=distance(arr,itr);
					}
					itr=find(arr,arr+n,rr2);
					if (itr==end(arr))
					{
						arr[index++]=rr2; rr2=index-1;
					}
					else
					{
						rr2=distance(arr,itr);
					}
					itr=find(arr,arr+n,ll1);
					if (itr==end(arr))
					{
						arr[index++]=ll1; ll1=index-1;
					}
					else
					{
						ll1=distance(arr,itr);
					}
					cout<<"ADD "<<"$"<<ll1<<", $"<<rr1<<", $"<<rr2<<endl;
				}
				else //one arg of rhs is numeric
				{
					int not_num=0;
					int ll1=stoi(rd.substr(1,eq-1));
					for(int i=0;i<line.length();i++)
					{
					  if(isdigit(line[i]))
					  continue;
					  else
					  {
						  not_num=1;
						  break;
					  }

					}
					if(not_num==0)
					{
					  int reg = stoi(r1.substr(2));
					  itr=find(arr,arr+n,ll1);
					if (itr==end(arr))
					{
						arr[index++]=ll1; ll1=index-1;
					}
					else
					{
						ll1=distance(arr,itr);
					}
					itr=find(arr,arr+n,reg);
					if (itr==end(arr))
					{
						arr[index++]=reg; reg=index-1;
					}
					else
					{
						reg=distance(arr,itr);
					}
					  cout<<"ADDI $"<<ll1<<", $"<<reg<<", #"<<line<<endl;
					}
				} 
			      }
				//end of addition
				//begin: Mutiplication : ASSUMING ITS 32 BIT.
			    if(line.find("*")>0 && line.find("*")<1000)
			    {
				int plus=line.find("*");
				r1=line.substr(0,plus); //rhs first
				
				line=line.substr(plus+1); //rhs second
				//cout<<"[[[[[[[[[[ RHS ARGS ]]]]]]]]]"<<line.substr(2)<<endl;
			     	//first: checking if they are already regs
				int rhs1 = r1.find("t");
				int rhs2 = line.find("t"); 
				if (rhs1!=-1 && rhs2!=-1 && rd.substr(0,1).compare("t")==0) 
				{
					int rr1=stoi(r1.substr(2));
					int rr2=stoi(line.substr(2));
					int ll1=stoi(rd.substr(1,eq-1));
					
					itr=find(arr,arr+n,rr1);
					if (itr==end(arr))
					{
						arr[index++]=rr1;rr1=index-1;
					}
					else
					{
						rr1=distance(arr,itr);
					}
					itr=find(arr,arr+n,rr2);
					if (itr==end(arr))
					{
						arr[index++]=rr2; rr2=index-1;
					}
					else
					{
						rr2=distance(arr,itr);
					}
					itr=find(arr,arr+n,ll1);
					if (itr==end(arr))
					{
						arr[index++]=ll1; ll1=index-1;
					}
					else
					{
						ll1=distance(arr,itr);
					}
					cout<<"MUL "<<"$"<<ll1<<", $"<<rr1<<", $"<<rr2<<endl;
				}
				
			    }
				//end of mult
				//begin: SUBTRACT
				if(line.find("-")>0 && line.find("-")<1000)
			      {
				int minus=line.find("-");
				r1=line.substr(0,minus); //rhs first
				
				line=line.substr(minus+1); //rhs second
				//cout<<"[[[[[[[[[[ RHS ARGS ]]]]]]]]]"<<line.substr(2)<<endl;
			     	//first: checking if they are already regs
				int rhs1 = r1.find("t");
				int rhs2 = line.find("t"); 
				if (rhs1!=-1 && rhs2!=-1 && rd.substr(0,1).compare("t")==0) 
				{
					int rr1=stoi(r1.substr(2));
					int rr2=stoi(line.substr(2));
					int ll1=stoi(rd.substr(1,eq-1));
					
					itr=find(arr,arr+n,rr1);
					if (itr==end(arr))
					{
						arr[index++]=rr1;rr1=index-1;
					}
					else
					{
						rr1=distance(arr,itr);
					}
					itr=find(arr,arr+n,rr2);
					if (itr==end(arr))
					{
						arr[index++]=rr2; rr2=index-1;
					}
					else
					{
						rr2=distance(arr,itr);
					}
					itr=find(arr,arr+n,ll1);
					if (itr==end(arr))
					{
						arr[index++]=ll1; ll1=index-1;
					}
					else
					{
						ll1=distance(arr,itr);
					}
					cout<<"SUB "<<"$"<<ll1<<", $"<<rr1<<", $"<<rr2<<endl;
				}
				
			      }
				//end of subtraction
				//begin: DV
				if(line.find("%")>0 && line.find("%")<1000)
			      {
				int mod=line.find("%");
				r1=line.substr(0,mod); //rhs first
				
				line=line.substr(mod+1); //rhs second
				//cout<<"[[[[[[[[[[ RHS ARGS ]]]]]]]]]"<<line.substr(2)<<endl;
			     	//first: checking if they are already regs
				int rhs1 = r1.find("t");
				int rhs2 = line.find("t"); 
				if (rhs1!=-1 && rhs2!=-1 && rd.substr(0,1).compare("t")==0) 
				{
					int rr1=stoi(r1.substr(2));
					int rr2=stoi(line.substr(2));
					int ll1=stoi(rd.substr(1,eq-1));
					
					itr=find(arr,arr+n,rr1);
					if (itr==end(arr))
					{
						arr[index++]=rr1;rr1=index-1;
					}
					else
					{
						rr1=distance(arr,itr);
					}
					itr=find(arr,arr+n,rr2);
					if (itr==end(arr))
					{
						arr[index++]=rr2; rr2=index-1;
					}
					else
					{
						rr2=distance(arr,itr);
					}
					itr=find(arr,arr+n,ll1);
					if (itr==end(arr))
					{
						arr[index++]=ll1; ll1=index-1;
					}
					else
					{
						ll1=distance(arr,itr);
					}
					cout<<"DIV "<<"$"<<rr1<<", $"<<rr2<<endl;
					cout<<"MFHI "<<"$"<<ll1<<endl; //reminder
				}
				
			      }
				//end of modulus
				if(line.find("/")>0 && line.find("/")<1000)
			      {
				int mod=line.find("/");
				r1=line.substr(0,mod); //rhs first
				
				line=line.substr(mod+1); //rhs second
				//cout<<"[[[[[[[[[[ RHS ARGS ]]]]]]]]]"<<line.substr(2)<<endl;
			     	//first: checking if they are already regs
				int rhs1 = r1.find("t");
				int rhs2 = line.find("t"); 
				if (rhs1!=-1 && rhs2!=-1 && rd.substr(0,1).compare("t")==0) 
				{
					int rr1=stoi(r1.substr(2));
					int rr2=stoi(line.substr(2));
					int ll1=stoi(rd.substr(1,eq-1));
			
					itr=find(arr,arr+n,rr1);
					if (itr==end(arr))
					{
						arr[index++]=rr1;rr1=index-1;
					}
					else
					{
						rr1=distance(arr,itr);
					}
					itr=find(arr,arr+n,rr2);
					if (itr==end(arr))
					{
						arr[index++]=rr2; rr2=index-1;
					}
					else
					{
						rr2=distance(arr,itr);
					}
					itr=find(arr,arr+n,ll1);
					if (itr==end(arr))
					{
						arr[index++]=ll1; ll1=index-1;
					}
					else
					{
						ll1=distance(arr,itr);
					}
					cout<<"DIV "<<"$"<<rr1<<", $"<<rr2<<endl;
					cout<<"MFLO "<<"$"<<ll1<<endl; //quotient
				}
				
			      }
				//end of divison
			    }
				else if (eq !=-1 && dbeq==-1 && neq==-1)
				{
					if (rd.substr(0,1).compare("t")==0)
					{
						//load inst
						
						reg=stoi(rd.substr(1,eq-1));
						itr=find(arr,arr+n,reg);
						if (itr==end(arr))
						{
							arr[index++]=reg; reg=index-1;
						}
						else
						{
							reg=distance(arr,itr);
						}
						
						cout<<"LW $"<<reg<<", "<<line<<endl;
					}
					else
					{
						//store inst
						int num=line.find("t");
						
						if (num!=-1)
						{
							reg=stoi(line.substr(num+1));
							itr=find(arr,arr+n,reg);
							if (itr==end(arr))
							{
								arr[index++]=reg; reg=index-1;
							}
							else
							{
								reg=distance(arr,itr);
							}
						}
						cout<<"SW "<<rd<<", $"<<reg<<endl;
					}
				}
				
				
				getline(f,line);
				//disp=disp+1;
			}
			//cout << "---------- End of label ------ " <<endl;

	}
	else if(line.find("end")==0)
	{
		cout<<"END OF PROGRAM"<<endl;
	}
 
	else
	{

	    string subs,r1,r2;
	    int eq=line.find("="),i;
	    int dbeq=line.find("==");
	    int neq=line.find("!=");
	    rd=line.substr(0,eq); //lhs
	    line=line.substr(eq+1);
	    //OPERATORS
	    
	    if((line.find("+")>0 && line.find("+")<1000) || (line.find("-")>0 && line.find("-")<1000) || (line.find("*")>0 && line.find("*")<1000)||(line.find("%")>0 && line.find("%")<1000) || (line.find("/")>0 && line.find("/")<1000))
    	{
      	if(line.find("+")>0 && line.find("+")<1000)
        {	
        int plus=line.find("+");
        r1=line.substr(0,plus); //rhs first
	
        line=line.substr(plus+1); //rhs second
	//cout<<"[[[[[[[[[[ RHS ARGS ]]]]]]]]]"<<line.substr(2)<<endl;
     	//first: checking if they are already regs
	int rhs1 = r1.find("t");
	int rhs2 = line.find("t"); 
	if (rhs1!=-1 && rhs2!=-1 && rd.substr(0,1).compare("t")==0) 
        {
		int rr1=stoi(r1.substr(2));
		int rr2=stoi(line.substr(2));
		int ll1=stoi(rd.substr(1,eq-1));
		
		itr=find(arr,arr+n,rr1);
		if (itr==end(arr))
		{
			arr[index++]=rr1;rr1=index-1;
		}
		else
		{
			rr1=distance(arr,itr);
		}
		itr=find(arr,arr+n,rr2);
		if (itr==end(arr))
		{
			arr[index++]=rr2; rr2=index-1;
		}
		else
		{
			rr2=distance(arr,itr);
		}
		itr=find(arr,arr+n,ll1);
		if (itr==end(arr))
		{
			arr[index++]=ll1; ll1=index-1;
		}
		else
		{
			ll1=distance(arr,itr);
		}
		cout<<"ADD "<<"$"<<ll1<<", $"<<rr1<<", $"<<rr2<<endl;
	}
	else //one arg of rhs is numeric
	{
		int not_num=0;
		int ll1=stoi(rd.substr(1,eq-1));
		for(int i=0;i<line.length();i++)
		{
		  if(isdigit(line[i]))
		  continue;
		  else
		  {
			  not_num=1;
			  break;
		  }

		}
		if(not_num==0)
		{
		  int reg = stoi(r1.substr(2));
		  
		itr=find(arr,arr+n,ll1);
		if (itr==end(arr))
		{
			arr[index++]=ll1; ll1=index-1;
		}
		else
		{
			ll1=distance(arr,itr);
		}
		itr=find(arr,arr+n,reg);
		if (itr==end(arr))
		{
			arr[index++]=reg; reg=index-1;
		}
		else
		{
			reg=distance(arr,itr);
		}
		  cout<<"ADDI $"<<ll1<<", $"<<reg<<", #"<<line<<endl;
		  
		}
	} 
      }
	//end of addition
	//begin: Mutiplication : ASSUMING ITS 32 BIT.
    if(line.find("*")>0 && line.find("*")<1000)
    {
        int plus=line.find("*");
        r1=line.substr(0,plus); //rhs first
	
        line=line.substr(plus+1); //rhs second
	//cout<<"[[[[[[[[[[ RHS ARGS ]]]]]]]]]"<<line.substr(2)<<endl;
     	//first: checking if they are already regs
	int rhs1 = r1.find("t");
	int rhs2 = line.find("t"); 
	if (rhs1!=-1 && rhs2!=-1 && rd.substr(0,1).compare("t")==0) 
        {
		int rr1=stoi(r1.substr(2));
		int rr2=stoi(line.substr(2));
		int ll1=stoi(rd.substr(1,eq-1));
		itr=find(arr,arr+n,rr1);
		if (itr==end(arr))
		{
			arr[index++]=rr1;rr1=index-1;
		}
		else
		{
			rr1=distance(arr,itr);
		}
		itr=find(arr,arr+n,rr2);
		if (itr==end(arr))
		{
			arr[index++]=rr2; rr2=index-1;
		}
		else
		{
			rr2=distance(arr,itr);
		}
		itr=find(arr,arr+n,ll1);
		if (itr==end(arr))
		{
			arr[index++]=ll1; ll1=index-1;
		}
		else
		{
			ll1=distance(arr,itr);
		}
		cout<<"MUL "<<"$"<<ll1<<", $"<<rr1<<", $"<<rr2<<endl;
	}
	
    }
	//end of mult
	//begin: SUBT$ACT
	if(line.find("-")>0 && line.find("-")<1000)
      {
        int minus=line.find("-");
        r1=line.substr(0,minus); //rhs first
	
        line=line.substr(minus+1); //rhs second
	//cout<<"[[[[[[[[[[ $HS ARGS ]]]]]]]]]"<<line.substr(2)<<endl;
     	//first: checking if they are already regs
	int rhs1 = r1.find("t");
	int rhs2 = line.find("t"); 
	if (rhs1!=-1 && rhs2!=-1 && rd.substr(0,1).compare("t")==0) 
        {
		int rr1=stoi(r1.substr(2));
		int rr2=stoi(line.substr(2));
		int ll1=stoi(rd.substr(1,eq-1));
		itr=find(arr,arr+n,rr1);
		if (itr==end(arr))
		{
			arr[index++]=rr1;rr1=index-1;
		}
		else
		{
			rr1=distance(arr,itr);
		}
		itr=find(arr,arr+n,rr2);
		if (itr==end(arr))
		{
			arr[index++]=rr2; rr2=index-1;
		}
		else
		{
			rr2=distance(arr,itr);
		}
		itr=find(arr,arr+n,ll1);
		if (itr==end(arr))
		{
			arr[index++]=ll1; ll1=index-1;
		}
		else
		{
			ll1=distance(arr,itr);
		}
		cout<<"SUB "<<"$"<<ll1<<", $"<<rr1<<", $"<<rr2<<endl;
	}
	
      }
	//end of subtraction
	//begin: DV
	if(line.find("%")>0 && line.find("%")<1000)
      {
        int mod=line.find("%");
        r1=line.substr(0,mod); //rhs first
	
        line=line.substr(mod+1); //rhs second
	//cout<<"[[[[[[[[[[ RHS ARGS ]]]]]]]]]"<<line.substr(2)<<endl;
     	//first: checking if they are already regs
	int rhs1 = r1.find("t");
	int rhs2 = line.find("t"); 
	if (rhs1!=-1 && rhs2!=-1 && rd.substr(0,1).compare("t")==0) 
        {
		int rr1=stoi(r1.substr(2));
		int rr2=stoi(line.substr(2));
		int ll1=stoi(rd.substr(1,eq-1));
		
		itr=find(arr,arr+n,rr1);
		if (itr==end(arr))
		{
			arr[index++]=rr1;rr1=index-1;
		}
		else
		{
			rr1=distance(arr,itr);
		}
		itr=find(arr,arr+n,rr2);
		if (itr==end(arr))
		{
			arr[index++]=rr2; rr2=index-1;
		}
		else
		{
			rr2=distance(arr,itr);
		}
		itr=find(arr,arr+n,ll1);
		if (itr==end(arr))
		{
			arr[index++]=ll1; ll1=index-1;
		}
		else
		{
			ll1=distance(arr,itr);
		}
		cout<<"DIV "<<"$"<<rr1<<", $"<<rr2<<endl;
		cout<<"MFHI "<<"$"<<ll1<<endl; //reminder
	}
	
      }
	//end of modulus
	if(line.find("/")>0 && line.find("/")<1000)
      {
        int mod=line.find("/");
        r1=line.substr(0,mod); //rhs first
	
        line=line.substr(mod+1); //rhs second
	//cout<<"[[[[[[[[[[ RHS ARGS ]]]]]]]]]"<<line.substr(2)<<endl;
     	//first: checking if they are already regs
	int rhs1 = r1.find("t");
	int rhs2 = line.find("t"); 
	if (rhs1!=-1 && rhs2!=-1 && rd.substr(0,1).compare("t")==0) 
        {
		int rr1=stoi(r1.substr(2));
		int rr2=stoi(line.substr(2));
		int ll1=stoi(rd.substr(1,eq-1));
		
		itr=find(arr,arr+n,rr1);
		if (itr==end(arr))
		{
			arr[index++]=rr1;rr1=index-1;
		}
		else
		{
			rr1=distance(arr,itr);
		}
		itr=find(arr,arr+n,rr2);
		if (itr==end(arr))
		{
			arr[index++]=rr2; rr2=index-1;
		}
		else
		{
			rr2=distance(arr,itr);
		}
		itr=find(arr,arr+n,ll1);
		if (itr==end(arr))
		{
			arr[index++]=ll1; ll1=index-1;
		}
		else
		{
			ll1=distance(arr,itr);
		}
		cout<<"DIV "<<"$"<<rr1<<", $"<<rr2<<endl;
		cout<<"MFLO "<<"$"<<ll1<<endl; //quotient
	}
	
      }
	//end of divison
    }
    	else if(eq!=-1 && dbeq==-1 && neq==-1)
	{
		if (rd.substr(0,1).compare("t")==0)
		{
						//load inst coz lhs is a temp
						reg=stoi(rd.substr(1,eq-1));
						itr=find(arr,arr+n,reg);
						if (itr==end(arr))
						{
							arr[index++]=reg; reg=index-1;
						}
						else
						{
							reg=distance(arr,itr);
						}
			cout<<"LW $"<<reg<<", "<<line<<endl;
		}
		else
		{
						//store inst
						int num=line.find("t");
						
						if (num!=-1)
						{
							reg=stoi(line.substr(num+1));
							itr=find(arr,arr+n,reg);
							if (itr==end(arr))
							{
								arr[index++]=reg; reg=index-1;
							}
							else
							{
								reg=distance(arr,itr);
							}
						}
			cout<<"SW "<<rd<<", $"<<reg<<endl;
		}
	}

  }
}
}
