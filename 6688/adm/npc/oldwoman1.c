//write by lysh
// Mon  08-21-95
inherit "/std/char/qlist.c";
inherit NPC;
int ask_jitang(); 
 
void create()
{
        int has_game;
        seteuid(getuid());
        set_name("老婆婆",({"old woman", "oldwoman", "woman"}));
        set("long", @TEXT 
TEXT
        );
        set("gender","女性");
        set("age",74);
        set("combat_exp",55);
        set("attitude","friendly");
        set("inquiry", ([
                "鸡汤" : (: ask_jitang :),
        ]));

        set("chat_chance_combat", 55);
        set("chat_msg_combat", ({
        (: this_object(), "ask_for_help" :) }) );
        setup();
        carry_object("/obj/cloth")->wear();
        add_money("coin",100);
}
 
void ask_for_help()
{
        object helper;
        helper = present("old man", environment(this_object()));
        if (!helper || helper->is_fighting()) return;
        tell_room(environment(helper), helper->name()+"叫道: 好啊,"+
        "敢砍我老婆, 去死吧!\n", ({this_object(), helper}) );
        helper->kill_ob(query_temp("killer"));
        return;
}
 
void kill_ob(object ob)
{
        set_temp("killer",ob);
        ::kill_ob(ob);
}
int ask_jitang()
{       
        object obj;       
	if(!this_player()->query_temp("acc-ji"))return 0;
	command ("say 老婆婆多谢你给的银鱼，这是我刚炖好的鸡汤，给你。\n");
        obj=new("/d/green/npc/obj/dahaiwan");
        obj->move(this_player());
        this_player()->set_temp("acc-ji",0);
        deal_quest(this_player(),"鸡汤");
       	return 1;
}
