// /obj/toy/exam_t.c

inherit ITEM;

void create()
{
        set_name("准考证", ({ "exam ticket", "card", "ticket",
                "exam_ticket" }) );
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long","这是一张普通的准考证,背面有说明(info).\n");
                set("nature", "测试");
                set("no_get",1);
                set("giver", "流浪猫");
        set("no_drop","你的准考证不能丢弃,也不能买卖或转让.\n");
        }
        setup();
}

void init()
{
        if( this_player()==environment() )
            add_action("do_info","info");
}

int do_info(string arg)
{
        string temp;
        temp=this_object()->query("nature");
        if (temp=="毕业")
        write("考场地点:"+this_object()->query("giver")+"隔壁的教室.\n");
        else write("考场地点:北京市考试中心(北大光华管理学院四楼)\n");
        return 1;
}
