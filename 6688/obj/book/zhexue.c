// /obj/book/zhexue.c

inherit ITEM;

void create()
{
        int temp;
        string *names = ({
                "黑格尔","尼采","弗洛伊德","马赫","马克思","叔本华",
                "卢梭","波普","萨特"
        });
        set_name(names[random(sizeof(names))], ({"philosophy book","book"}));
        temp = 1800+random(20)*100;
        set_weight(temp);
        set("unit", "本");
        set("long", "这是时下流行的哲学著作.\n");
        set("value", temp*2);
        set("skill", ([
                "name"          : "philosophy",
                "exp_required"  : 0,
                "sen_cost"      : 35+random(35),
                "difficulty"    : 50+random(50),
                "max_skill"     : 88,
                "base_skill"    : "literate",
          "base_skill_level"    : 66,
        ]) );
}
