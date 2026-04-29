//suqier.c
//create by dongsw@zhtx2

#include <ansi.h>
inherit NPC;
int ask_killer();

void create()
{
        set_name("苏乞儿" , ({ "su qier", "qier" }) );
        set("long",
        "这位英俊小伙就是今年的武状元得主，身手甚是不凡。\n"
        );
        set("gender", "男性");
        set("age", 22);
        set("title", HIR"武状元"NOR);
        set("nickname", HIC"万事通"NOR);
        set("combat_exp", 5000000);
        setup();

        set("inquiry",([
                        "乾坤教" : (:ask_killer:),
                        "乾坤教徒" : (:ask_killer:),
                        "杀手" : (:ask_killer:),
                        "killer" : (:ask_killer:),
                        ]));
        add_money("silver", 10);
}
int ask_killer()
{
        object me, ob, killer, position;
        me = this_player();
        ob = this_object();
        killer = me->query("cttask/killer");

        if (killer)
        position = environment(killer);
        
        if(!me->query("cttask/get"))
                return notify_fail(CYN"苏乞儿说道：你没有朝廷的任务来问什么问？\n"NOR);
        
        if ( (int)me->query("deposit") < 10000 )
                return notify_fail(CYN"苏乞儿说道：你怎么不懂规矩，每次打探消息要一两黄金的费用。\n"NOR);

        message_vision(CYN"$N说道：武状元乃丐帮中人，不知在丐帮地面可否有乾坤教徒活动的消息？\n"NOR, me);
        message_vision(CYN"$N说道：丐帮乃中原第一大帮，耳目遍部天下，岂有不知之理？\n"NOR, ob);

        if (!position)
                message_vision(HIY"\n苏乞儿在你的耳边悄声说道：我也不太清楚呀！\n"NOR, me);
        else
                message_vision(HIY"\n苏乞儿在你的耳边悄声说道：我一名手下说在" + (string)position->query("short") + "地面有乾坤教徒活动的踪影。\n"NOR, me);
                
        return 1;
}

