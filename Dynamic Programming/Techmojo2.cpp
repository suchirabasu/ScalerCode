void FunctionGenerator(vector<int> array){
    int n = array.size();
    int sum;
    for(int i=0;i<n;i++){
        sum = 0;
        sum = array[i] + 10;
        sum = sum/2;
        sum = sum*2;
        cout<<

    }
}
template <typename T>
class Filter{
    public:
        virtual T apply(T input) = 0;

};


class FilterPipeline{
    private:
        vector<Filter<T>*> filters;
    public:
        void addFilter(Filter<T>* filter){
            filters.push_back(filter);
        }
        T apply(T input){
            for(Filter<T>* filter:filters){
                input = filter->apply(input);
            }
            return input;
        }
};
class AddFilter : public Filter<T>{
    private:
        T addend;
    public:
        AddFilter(T value) : addend(value) {}
        T apply(T input) override {
            return input + addend;
        }
};
class DivFilter : public Filter<T>{
    private:
        T divisor;
    public:
        DivFilter(T value) : divisor(value) {}
        T apply(T input) override {
            return input / divisor;
        }
};
class ProdFilter : public Filter<T>{
    private:
        T multi;
    public:
        ProdFilter(T value) : multi(value) {}
        T apply(T input) override {
            return input * multi;
        }
};

int solve(){
    FilterPipeline<int> pipeline;
    pipeline.addFilter(new AddFilter<int>(10));
    pipeline.addFilter(new ProdFilter<int>(2));
    pipeline.addFilter(new DivFilter<int>(2));
    int num;
    while(cin>>num){
        int filtered = pipline.apply(num);
        cout<<filtered<<endl;
    }
    return 0;
}

class FilterPipeline{
    private:
        list<Filter<T>*> filters;
        unordered_map<Filter<T>*, typename list<Filter<T>*>::iterator> filter_positions;
    public:
        void addFilter(Filter<T>* filter){
            filters.push_back(filter);
        }
        T apply(T input){
            for(Filter<T>* filter:filters){
                input = filter->apply(input);
            }
            return input;
        }
        filters.erase(filter_positions[filter]);
        filter_positions.erase(filter);
};



