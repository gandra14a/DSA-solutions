#ifdef PROBLEM1
void problem1_example()
{
    std::vector <int> list_of_numbers = {8, 7, 2, 5, 3, 1};
    int target = 10;

    FindPairsOfSum prob1;

    prob1.setNums(list_of_numbers);
    prob1.setSum(target);

    prob1.bruteForceFind();
    prob1.sortFind();
    prob1.hashFind();

    return;
}
#endif // PROBLEM1


#ifdef PROBLEM4
void problem4_example()
{
    std::vector<int>  numbers_list = { 1, 0, 1, 0, 1, 0, 0, 1 };

    SortBinaryArrayInLinearTime prob1(numbers_list);

    prob1.mySolution();
    prob1.countZerosSolution();
    prob1.solution3();
    prob1.pivotSolution();
}
#endif // PROBLEM4



#ifdef PROBLEM7
void problem7_example()
{
    std::vector<int> my_numbers = {-10, -3, 5, 6, -2};

    MaximumProduct prob1(my_numbers);

    //prob1.bruteForceSolution();
    //prob1.sortSolution();
    prob1.linearTimeSolution();
}
#endif // PROBLEM7


#ifdef PROBLEM14
void problem14_example()
{
    std::vector<int> my_numbers = {0, -3, 5, -4, -2, 3, 1, 0};

    EquilibriumIndex prob1(my_numbers);

    prob1.quadraticTimeSolution();

    prob1.linearTimeSolution();

    prob1.optimizedSolution1();

    prob1.optimizedSolution2();
}
#endif // PROBLEM14


#ifdef PROBLEM16
void problem16_example()
{
    int my_numbers[] = {2, 8, 7, 2, 2, 5, 2, 3, 1, 2, 2};
    int length = sizeof(my_numbers)/sizeof(int);

    MajorityElement prob1(my_numbers, length);


}
#endif // PROBLEM16
