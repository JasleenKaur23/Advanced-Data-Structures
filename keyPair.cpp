/* key pair to find the program having the keys
 whose sum is as given*/
 #include<iostream>
 #include<string>
 #include<unordered_map>
 using namespace std;
string getKeyPair(int *a , int n , int sum)
 { int i;
 	unordered_map<int, int> m;
 	for( i=0;i<n;i++)
 	{
 		m[a[i]]++;
 		
 	}
 	int twice_cnt=0;
	for(i=0;i<n;i++)
 	{
 		twice_cnt+=m[sum-a[i]];
 		
 		if(sum-a[i]==a[i])
 		{
 			twice_cnt--;
 		}
 		if(twice_cnt>0)
 	{
 		return "Yes";
 	}
 	}
 	
 	return "No";
 }
 int main()
 {
 	int n,i,sum,T;
 	int *a;
 	cin>>T;
 	while(T--){
	 cin>>n;
 	 cin>>sum;
	 a=new int(n);
 	for(i=0;i<n;i++)
 	{
 		cin>>a[i];
 	}
 	
 	cout<< getKeyPair(a,n,sum)<<endl;
 	
 	delete(a);
 	}
 	return 0;
 }
