// /d/chaoting/npc/shangshu_hubu.c
// chaoting system
// dongsw created for zh2 in 2002.5

#include <ansi.h>

inherit NPC;

string change_name();
int do_change(string name);

void create()
{
        set_name("户部尚书" , ({ "hubu shangshu", "shangshu" }) );

        set("title",HIY"朝廷大臣"NOR);

        set("long",
        "朝廷中主管户部的官员，主管户口等等，现在可以在他这里更改名字。\n"
        );

        set("gender", "男性");

        set("age", 35);


        set("inquiry",([
                        "更改名字":(:change_name:),
                        "名字":(:change_name:),
                        "姓名":(:change_name:),
                        "name":(:change_name:),
                        ]));
        setup();

}
void init()
{
        add_action("do_change","change");
}
string change_name()
{
        object me=this_player();

        if(me->query("hubu_change"))
        return "您只能更改一次姓名。\n";

        me->set_temp("hubu_asked",1);

        return "国家规定，每次改名要叫一千两黄金的费用，快快交费吧！";
}
int accept_object(object me, object ob)
{
        object obj=present("hubu shangshu",environment());

        if( ( ob->value() < 10000000)||!me->query_temp("hubu_asked"))
        {
               message_vision(CYN"$N说到：多谢您支持国家建设！\n"NOR,obj);
               return 1;
        }
        else
        {
               message_vision(CYN"$N说到：好了，您现在可以用 change 姓名 来更改您的姓名。您的姓名只能更改一次，请注意！\n"NOR,obj);
               me->set("hubu_gived",1);
               return 1;
        }
        return 0;
}
int do_change(string name)
{
        object me=this_player();
        object ob=this_object();

        if (me->query("hubu_change"))
        return notify_fail("您只能改一次名字。\n");

        if (!me->query("hubu_gived"))
        return notify_fail("请先交费。\n");

        if (!name)
        return notify_fail("您要改什么名字？\n");

        if( (strlen(name) < 4) || (strlen(name) > 8 ) || (strlen(name) % 2))
        return notify_fail("对不起，你的中文名字必须是 2 到 4 个中文字。\n");

        if(name == "晓风残月")
          return notify_fail("你给我去死！\n");
        CHANNEL_D->do_channel(ob,"chat",me->query("name")+"从今以后改名叫"+name+"，希望大家相互转告以免认错人！\n");
        me->set("name",name);
        me->set("hubu_change",1);
        me->delete("hubu_gived");
        me->delete_temp("hubu_asked");
        return 1;
}

