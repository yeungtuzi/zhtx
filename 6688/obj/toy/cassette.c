// /obj/toy/cassette.c

inherit ITEM;

void create()
{
        string *names = ({
                "惠特尼.休斯顿", "麦克.博顿", "玛丽亚.凯莉", "约翰.列农",
                "王子", "U-2", "Boyz2man", "Eagles", "麦克尔.杰克逊",
                "猫王", "崔健", "孟庭苇"
        });
        set_name("乐曲磁带", ({"cassette" }) );
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "盘");
                set("long","这是一盘"+names[random(sizeof(names))]+
                   "的磁带.\n");

        set("value", 1000);
        set("skill", ([
                "name":                 "music",
                "exp_required": 0,
                "sen_cost":             20,
              "difficulty":   random(30)+10,
               "max_skill":   random(50)+10,
        ]) );
        }
}

