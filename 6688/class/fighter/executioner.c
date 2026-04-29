// executioner.c

#include <ansi.h>

inherit NPC;
inherit F_QUEST;     
inherit F_MASTER;

void create()
{
        set_name("潘军禅", ({ "master executioner", "executioner", "master" }) 
);
        set("title", "水烟阁执法使");
        set("nickname", HIC "书 剑 侠" NOR);
        set("gender", "男性");
        set("age", 28);
        set("long",
                
"潘军禅是当今武林的一位传奇性人物，以他仅仅二十八岁的年龄竟能做到\n"
                
"水烟阁执法使的职位，著实是一位不简单的人物。潘军禅是封山剑派掌门\n"
                
"柳淳风的结拜义弟，但是他为人其实十分风趣，又好交朋友，丝毫不会摆\n"
                "出武林执法者的架子。\n" );

        set("attitude", "friendly");
        set("combat_exp", 1000000);
        set("score", 200000);

        set("str", 50);
        set("int", 30);
        set("cor", 30);
        set("cps", 30);
        set("con", 30);
        set("dex", 30);

        set("force", 6000);
        set("max_force", 3000);
        set("force_factor", 100);
	set("max_sen",1000);
	set("max_gin",1000);
	set("max_kee",10000);	
	
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }) );

        set_skill("force", 150);
        set_skill("strike", 150);
        set_skill("sword", 150);
        set_skill("parry", 150);
        set_skill("dodge", 180);
        set_skill("move", 180);
        set_skill("celestial", 150);
        set_skill("celestrike", 150);
        set_skill("pyrobat-steps", 180);
        set_skill("six-chaos-sword", 150);

        map_skill("force", "celestial");
        prepare_skill("strike", "celestrike");
        map_skill("strike", "celestrike");
        map_skill("sword", "six-chaos-sword");
        map_skill("dodge", "pyrobat-steps");
        map_skill("move", "pyrobat-steps");
        
	set("shen_type",-1);
        create_family("天邪派", 16, "弟子");

        setup();

        carry_object(__DIR__"soulimpaler")->wield();
}

void init() {

        add_action("do_swear","swear");
        add_action("give_quest","quest");
	::init();

}
 
void attempt_apprentice(object me)
{
	if( me->query_temp("pending/celestial_swear") ) {
		command("say 多说无益，若不发誓恪守门规，便是跪著求我也没用。");
		return;
	} else {
		command("say 我天邪派门规甚严，" + RANK_D->query_respect(me)
			+ "如果真的有心，且发个誓(swear)来。");
		me->set_temp("pending/celestial_swear", 1);
	}
}

int do_swear(string arg)
{
	if( !this_player()->query_temp("pending/celestial_swear") )
		return 0;
	if( !arg ) return notify_fail("你要发什麽誓？\n");
	this_player()->set_temp("pending/celestial_swear", 0);
	message_vision("$N发誓道：" + arg + "\n", this_player());
	if( strsrch(arg, "守") >=0 && strsrch(arg, "门规") >=0
	&&	strsrch(arg, "不") <0 	&&	strsrch(arg, "鬼") <0	&&	strsrch(arg, "头") <0) {
		command("smile");
		command("say 这就是了。\n");
		command("recruit " + this_player()->query("id"));
	} else {
		command("say 你发的是什麽鬼誓，别以为我没听到！");                              
		command("kick");
	}
	return 1;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		add("apprentice_availavble", -1);
}
