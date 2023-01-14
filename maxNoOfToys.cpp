 vector<int>  ans;
      
      vector<pair<int,int>> temp;  //val , idx
      vector<long long int>prefixsum(N);
      
      for(int i = 0;i<N;i++)
      {
      temp.push_back({A[i] ,i})   ;
      }
      
      sort(temp.begin() ,temp.end());
      
      prefixsum[0] = temp[0].first;
      
      //finding prefix sum
      for(int i =1;i<N;i++)
      {
          prefixsum[i] = prefixsum[i-1] +temp[i].first;
      }
      
      
      //maximising the toys 
      for(auto q : Queries)
      {
          int cost = q[0];
          int k =q[1]; //brolen toys 
          int toys = 0;
          
          //can't even buy the single toy 
          if(cost<temp[0].first){ans.push_back(0);continue;} 
          
          //uptil what index can we buy toys considering if not broken toys in b/w 
          int idx = lower_bound(prefixsum.begin() ,prefixsum.end() ,cost) - prefixsum.begin();
          
          if(idx<N && prefixsum[idx] ==cost)
          {
              cost=0; toys = idx+1;
          }
          else
          {
              toys = idx; cost -= prefixsum[idx-1]; idx--;
          }
          
          //all broken toys index 
          unordered_set<int> set;
          
          //removing broken toys from our selected range i.e prefix from starting
          //saving that money to buy toys in further forward indexes 
          for(int i =2;i<k+2;i++)
          {
              int bidx = q[i] -1;  //broken index
              
              //a broken toys in our selected range neglect it and dnt buy it
              if(A[bidx] <temp[idx].first) 
              {
                  toys--;
                  cost+=A[bidx];
              }
              else if(A[bidx] == temp[idx].first && bidx <=temp[idx].second)
              {
                  toys--;cost+=A[bidx];
              }
              
              set.insert(bidx);
          }
          
          idx++;
          //move further select more items until left cost gets covered
          //buy more and more toy
          while(idx <N && cost >=temp[idx].first)
          {
              //not broken
              if(set.find(temp[idx].second) == set.end())
              {
                  //take it
                  cost-=temp[idx].first;toys++;
              }
              idx++;
          }
          
          
          if(toys >0)ans.push_back(toys);
          else{ans.push_back(0);}
      }
      
      return ans;
