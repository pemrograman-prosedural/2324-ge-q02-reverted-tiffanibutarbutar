#include "gender.h"

const char* get_gender_string(enum gender_t gender)
{
    switch (gender) {
        case GENDER_FEMALE: 
            return "Female";
        case GENDER_MALE:
            return "Male";
        default:
            return "Invalid";
    }
}