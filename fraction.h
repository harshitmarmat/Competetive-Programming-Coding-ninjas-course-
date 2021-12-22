class fraction{
    int numerator;
    int denominator;

    public:
        
        fraction( int numerator , int denominator){
            
            this -> numerator = numerator;
            this -> denominator = denominator;

        }

        void simplify(){
            int mini = min(this -> numerator , this -> denominator);
            // cout<<mini<<endl;
            int gcd = 1;
            for(int i =1 ; i<= mini ; i++){
                if( this -> numerator % i == 0 && this -> denominator % i == 0){
                    if(i>gcd){
                        gcd = i;
                    }
                }
            }
            // cout<<gcd<<endl;
            this -> numerator /= gcd;
            this -> denominator /= gcd;
        }

        void display(){
            simplify();
            cout <<"Fraction : "<<numerator<<"/"<<denominator<<endl;
        }

        fraction operator+(fraction const &f)const{
            int num = ((this -> numerator)* (f.denominator))+((this ->denominator)*(f.numerator));
            int den = this -> denominator * f.denominator;
            fraction fnew(num,den);
            fnew.simplify();
            return fnew; 

        }

        fraction operator*(fraction const &f) const{
            int num = this -> numerator * f.numerator;
            int den = this -> denominator * f.denominator;
            fraction fnew ( num , den );
            return fnew;
        }

        fraction & operator++(){
            this -> numerator += this -> denominator;
            simplify();
            return *this;
        }

        fraction operator++(int){

            fraction fnew(numerator , denominator);
            this -> numerator += this ->denominator;
            simplify();
            fnew.simplify();
            return fnew;

        }

        fraction & operator+=(fraction f){
            int num = ((this -> numerator)* (f.denominator))+((this ->denominator)*(f.numerator));
            int den = this -> denominator * f.denominator;
            this -> numerator = num;
            this -> denominator = den;
            simplify();
            return *this;
        }

};