class Date {
public:
    Date();
    ~Date ();

    char *getCurrentDate() const;

private:
    int day, month, year;
    char* currentDate;
};
