// /d/xizang/npc/yecha.c
// modified by mscat
// master.c

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("夜叉王", ({ "yecha wang", "yecha", "wang" }) );
	set("nickname", HIY"流氓老大"NOR);
	set("gender", "男性");
	set("age", 32);
	set("long", @LONG
    他是这个地方不三不四的人的老大,整天嘻皮笑脸地站在大路中间骚扰
过往行人.他的功夫不错,所以没谁敢得罪他.而且他也没做过多少真正的坏
事,连官府也懒得理会他.
LONG
            );
	set("attitude", "peaceful");

	set("str", 30);
	set("int", 20);
	set("cor", 20);
	set("cps", 20);
        set("per", 21);

	set("force", 2000);
	set("max_force", 1000);
	set("force_factor", 50);

	set("combat_exp", 120000);
	set("score", 200);
	set("shen", -100);
        set("bellicosity",3);
	set("env/wimpy", 50);
	
	set("chat_chance", 5);
     	set("chat_msg", ({
		(: random_move :),
	}) );

	set("inquiry", ([
		"宝藏" : "去找吧,快去找吧,找到了别忘分我一份儿!",
		"传说" : "我没听到过,问别人吧.",
		"英雄" : "在下就是通天彻地,震古烁今的第一大..大..大..英雄!",
		"发财" : "你们都给我钱,我就发财啦!"
	]));

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
                (: random_move :),
	}) );

	set_skill("unarmed", 100);
	set_skill("force", 200);
	set_skill("parry",100);
        set_skill("dodge",100);
        set_skill("move",100);
        set_skill("literate",20);
	set_skill("dancing", 10);

        map_skill("dodge","dancing");
	map_skill("move", "dancing");
       
	set("class", "legend");

	setup();
        carry_object(OBJ_DIR"cloth")->wear();
}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(3) ) {
                case 0:
        say( "夜叉王嘻皮笑脸地说道: 欢迎来到拉萨,请交保护费一gold...\n");
		break;
		case 1:
			command("walkby");
			break;
		case 2:
			command("xixi "+ob->query("id"));
			command("face");
			break;
	}
}

int accept_object(object who, object ob)
{
        int val;

        val = ob->value();
        if( !val )
                return notify_fail("什么破铜烂铁也给我?哼!\n");
	command("thank "+who->query("id"));
	if(val>10000) {
		say("我会尽量保护你的.");
		this_object()->set_leader(who);
		this_object()->set_temp("guarding", who);
	}
	return 1;
}
