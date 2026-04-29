// /obj/toy/musiccd.c

inherit ITEM;

void create()
{
        string *names = ({
                "玛丽亚.凯莉", "孟庭苇", "巫启贤", "李宗盛",
                "成龙", "张惠妹", "罗大佑", "黑豹", "齐豫",
                "约翰.列农"
        });
        set_name("音乐CD", ({ "music cd", "cd" }) );
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "盘");
                set("long","这是一盘"+names[random(sizeof(names))]+
                   "的唱碟.\n");
        set("value", 1300);
        set("skill", ([
                "name":                 "music",
                "exp_required": 0,
                "sen_cost":             20,
              "difficulty":   random(30)+10,
               "max_skill":   random(50)+10,
        ]) );
        }
}

