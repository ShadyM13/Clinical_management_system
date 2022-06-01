typedef     unsigned char           u8;
typedef     unsigned short int      u16;
typedef     unsigned long int       u32;
typedef     signed char             s8;
typedef     signed short int        s16;
typedef     signed long int         s32;
typedef     float                   f32;
typedef     double                  f64;

#define     CONFIG_PASSWORD         1234

typedef struct node
{
    char  name[10];
    u8    age;
    char  gender[10];
    u32   ID;
    struct node* link;

} node;


node* head = NULL;
u16 count;

void Screeninit(void);
int  SelectMode(void);
u8   check_admin(void);
void UserMode(void);
void Exit(void);
void AdminChoices(void);
void add_record(void);
void print_linkedlist(void);
u8   search(u32 ID);
void add_node(u32 ID, char name[10], u8 age, char gender[10]);
void edit_node(u32 ID, char name[10], u8 age, char gender[10]);
void edit_record(void);
void PrintReservationtime(void);
void ReservingTimeSlot(void);
void GetPatientRecord(void);

static  u32 ReservationArray[5];
static  char Time_Slots[5][30]   = {{"2:00 pm to 2:30 pm Press : 1"},    /* Time Slots of Reservation */
                                    {"2:30 pm to 3:00 pm Press : 2"},
                                    {"3:00 pm to 3:30 pm Press : 3"},
                                    {"3:30 pm to 4:00 pm Press : 4"},
                                    {"4:00 pm to 4:30 pm Press : 5"}
                                   };