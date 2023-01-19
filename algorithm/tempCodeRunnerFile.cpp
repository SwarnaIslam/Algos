while(l<r){
        ll m=(l+r)/2;
        ll ny=(c-a*m)/b;
        if(ny>=lx2)r=m;
        else l=m+1;
        cout<<l<<" "<<r<<endl;
    }