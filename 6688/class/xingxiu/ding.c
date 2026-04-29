#include <ansi.h>

inherit "/u/z/zephyr/revengenpc.c";
inherit F_MASTER;
inherit F_QUEST;
inherit "/feature/challenge";

int ask_san();

void create()
{
        set_name("丁春秋", ({ "ding chunqiu", "ding" }));
        set("nickname", "星宿老怪" );
	set("title", "星宿派掌门");
        set("long", @LONG
他手摇鹅毛扇，脸色红润，满头白发，三缕银髯，童颜鹤发，
恍如神仙。谁又料想得到他就是令正派人士深恶痛绝的星宿老怪丁春秋？
LONG);
        set("gender", "男性");
        set("age", 60);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 35);
        set("int", 30);
        set("con", 28);
        set("per", 28);
        set("max_kee", 4000);
        set("max_gin", 300);
        set("max_sen", 300);
        set("atman", 300);
        set("max_atman", 300);
        set("mana", 300);
        set("max_mana", 300);
        set("force", 2000);
        set("max_force", 2000);
        set("force_factor", 100);
        set("combat_exp", 1500000);
        set("shen",-150000);
        set("score", 400000);

        set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
                (: exert_function,"san" :),
        }) );
	set("inquiry", ([
		"三笑逍遥散" : (: ask_san :),
	]));

        set_skill("force", 180);
        set_skill("huagong-dafa", 200);
        set_skill("dodge", 180);
        set_skill("strike", 180);
        set_skill("xingxiu-duzhang", 180);
        set_skill("parry", 180);
        set_skill("literate", 80);
	set_skill("dugong", 200);
	set_skill("fushi-dugong", 200);

        map_skill("force", "huagong-dafa");
        map_skill("strike", "xingxiu-duzhang");
        map_skill("parry", "xingxiu-duzhang");
        map_skill("dugong", "fushi-dugong");

        prepare_skill("strike", "xingxiu-duzhang");

        create_family("星宿派", 1, "掌门");

        setup();
      	carry_object(__DIR__"xiaoyaosan");
	carry_object(__DIR__"cyn_robe")->wear();
	carry_object(__DIR__"fan");
}

void init()
{
	object ob;

        add_action("do_flatter", "flatter");
        add_action("give_quest","quest");
        ::init();

	if( interactive(ob = this_player()) && !is_fighting() ){
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if( ob->query("title") == "星宿派大师兄"
	|| ob->query("title") == "星宿派大师姐" )
		command("hehe "+ob->query("id"));
	return;
}

int ask_san()
{
	return 1;
}

void attempt_apprentice(object me)
{
        if( (int)me->query("shen") > 0 ){
                command("say 老仙越看你越象白道派来卧底的。");
                return;
        }

        if( me->query_temp("pending/flatter") ) {
                command("say 你如此不把老仙放在眼里，老仙怎会收你？");
                return;
        } 
	else{
                command("say 我星宿老仙比起古往今来的圣人怎么样啊？");
                message_vision("星宿老怪微闭双眼，手捻长须，一付等人拍马(flatter)的样子。\n", this_player());
                me->set_temp("pending/flatter", 1);
        }
}

int do_flatter(string arg)
{
	object me;

	me = this_player();

        if( !this_player()->query_temp("pending/flatter") )
                return 0;

        if( !arg ) return notify_fail("你说老仙什么？\n");

        this_player()->delete_temp("pending/flatter");
        message_vision("$N大声说道：" + arg + "\n", this_player());
        if( strsrch(arg, "星宿老仙") >=0 && (strsrch(arg, "德配天地") >=0
         || strsrch(arg, "威震寰宇") >=0 || strsrch(arg, "古今无比") >=0 )){
		command("smile");
                command("say 这还差不多。\n");
           	command("recruit " + this_player()->query("id"));
        } 
	else{
                command("say 你如此不把老仙放在眼里，老仙怎会理你？");
        }
        return 1;
}
