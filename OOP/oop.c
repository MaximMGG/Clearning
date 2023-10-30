#include <string.h>
#include <stdio.h>
#include "my_string.h"


struct s_student {
    int age;
    char name[40];
};


void student_init(struct s_student *this, int age, const char *name) {
    strcpy(this->name, name);
    this->age = age;
    printf("I AM CREATED: %s - %d\n", this->name, age);
}

void aging(struct s_student *this) {
    (this->age)++;
    printf("%s: I'm now %d years old\n", this->name, this->age);
}

void print(const struct s_student *this) {
    printf("%s - %d\n", this->name, this->age);
}

void destructor(struct s_student *this) {
    free(this);
    printf("I AM DESTROYED\n");
    print(this);
}

int main() {


    // m_string *p = cr_str("Hello");
    // printf("%s\n", p->str);
    //
    // char *example = "My name is Bob";
    //
    // p->fm_strcpy(p, example);
    // printf("%s\n", p->str);

    m_string *str = cr_str(str_format("Hello %s, I am very besy", "Bobbi"));
    printf("%s\n", str->str);

    return 0;
}
