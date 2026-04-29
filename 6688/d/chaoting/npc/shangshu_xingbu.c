// /d/chaoting/npc/shangshu_xingbu.c
// chaoting system
// dongsw created for zh2 in 2002.5

#include <ansi.h>

inherit NPC;

string ask_pker();

void create()
{
        set_name("刑部尚书" , ({ "xingbu shangshu", "shangshu" }) );

        set("title",HIY"朝廷大臣"NOR);

        set("long",
        "刑部尚书。\n"
        );

        set("gender", "男性");

        set("age", 35);


        set("inquiry",([
                        "pker":(:ask_pker:),
                        "凶手":(:ask_pker:),
                        "杀人犯":(:ask_pker:),
                        ]));
        setup();

}

string ask_pker()
{
        object me=this_player();
        string msg=me->query("pker_id");
        object ob;
        ob = find_player(msg);

        if (!me->query("pker_name"))
        return "你以前没被人杀过。\n";
        message_vision("$N上前躬身说道：尚书大人:请帮助缉拿要犯"+me->query("pker_name")+",替小民申冤!\n",me);
        this_object()->move(environment(ob));
        message_vision(HIR"只见突然出现几个侍卫把$N绑了起来。\n"NOR     ,ob);
        ob->move("/d/wizard/jianyu");
        message("channel:chat",HIY+"官府通告："+me->query("pker_name")+"因犯杀人罪入狱一年，以作惩戒。\n"+NOR,users());
        me->delete("pker_name");
        me->delete("pker_id");
        return "犯人已经入狱，请你放心。";
        destruct(this_object());

}

