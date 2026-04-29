// /d/chaoting/npc/shangshu_libu.c
// chaoting system
// dongsw created for zh2 in 2002.5

#include <ansi.h>

inherit NPC;

string change_rank();
int do_change(string rank);

void create()
{
        set_name("礼部尚书" , ({ "libu shangshu", "shangshu" }) );

        set("title",HIY"朝廷大臣"NOR);

        set("long",
        "朝廷中主管礼法的大臣，在这里可以给自己起绰号。\n"
        );

        set("gender", "男性");

        set("age", 35);


        set("inquiry",([
                        "更改绰号":(:change_rank:),
                        "绰号":(:change_rank:),
                        "rank":(:change_rank:),
                        ]));
        setup();

}
void init()
{
        add_action("do_change","change");
}
string change_rank()
{
        object me=this_player();

        if (me->query("combat_exp")<3000000||me->query("wlshw")<10)
        return "这么点本事还想取绰号？不怕人家笑掉大牙！";

        if (me->query("ct_faith")<10||me->query("tactic_exp")<500000)
        return "你对朝廷贡献这么少，我可不管你的鸟事！";

        me->set_temp("libu_asked",1);

        return "每起一次绰号需要一百两黄金宣传费，快交钱吧！";
}
int accept_object(object me, object ob)
{
        object obj=present("libu shangshu",environment());

        if( ( ob->value() < 1000000)||!me->query_temp("libu_asked"))
        {
               message_vision(CYN"$N说到：多谢您支持国家建设！\n"NOR,obj);
               return 1;
        }
        else
        {
               message_vision(CYN"$N说到：好了，您现在可以用 change 绰号 来更改您的绰号。\n"NOR,obj);
               me->set("libu_gived",1);
               return 1;
        }
        return 0;
}
int do_change(string rank)
{
        object me=this_player();
        object ob=this_object();

        if (!me->query("libu_gived"))
        return notify_fail("请先交费。\n");

        if (!rank)
        return notify_fail("您要改什么绰号？\n");

        if( (strlen(rank) < 4) || (strlen(rank) > 8 ) || (strlen(rank) % 2))
        return notify_fail("对不起，你的中文绰号必须是 2 到 4 个中文字。\n");

        CHANNEL_D->do_channel(ob,"chat",me->query("name")+"自封为"+rank+"，特此公告！\n");
        me->set("rank_info",rank);
        me->delete("hubu_gived");
        me->delete_temp("hubu_asked");
        return 1;
}

