 unordered_map<Node*,int> mp;

        Node *temp=head;

        while(temp!=NULL){

            if(mp.find(temp)==mp.end()){

                 mp[temp]=temp->data;

              }

             else

                return mp[temp];

                

                temp=temp->next;

         }

        return -1;
