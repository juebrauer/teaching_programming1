class NumberBox
{
   public:
   
      NumberBox(int max_size);
      ~NumberBox();

      void add_a_number(double n);

      void show_numbers();

      void get_min_and_max(double* minval, double* maxval);

      void delete_specific_number(double n);

   private:

      double* A;

      int     current_size;
      int     maximum_size;

};