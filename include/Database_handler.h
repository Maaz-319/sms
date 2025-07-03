#pragma once
#include "Person.h"
void save_person(Person **person);
Person **read_person(int *ids, int &current_id);