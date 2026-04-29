// d/xizang/class/budala/npc/tiger.c

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name(HIY"老虎"NOR, ({"tiger","jinwandalaohu","hu"}));
	set("gender", "男性" );
	set("age", 53);
	set("attitude", "heroism");
	set("title", "守卫统领");
	set("long", @LONG
    他是布达拉宫守卫的统领,是远近闻名的勇士,曾赤手生擒一只猛虎,后
来人们就都叫他"老虎",以至于忘记了他真正的姓名.
LONG
);
	set("str", 63);
	set("cor", 36);
	set("int", 30);
	set("spi", 30);
	set("cps", 35);
	set("per", 26);
	set("con", 69);
	set("shen", -538480);
	set("combat_exp", 1601591);
	create_family("布达拉宫", 15, "大喇嘛");
	set_skill("bloodystrike", 180);
	set_skill("bolomiduo", 200);
	set_skill("zang-buddhi", 177);
	set_skill("cloudstaff", 200);
	set_skill("dodge", 157);
	set_skill("essencemagic", 178);
	set_skill("force", 200);
	set_skill("iron-cloth", 184);
	set_skill("jin-gang", 200);
	set_skill("literate", 201);
	set_skill("magic", 148);
	set_skill("move", 157);
	set_skill("notracesnow", 180);
	set_skill("parry", 197);
	set_skill("perception", 94);
	set_skill("staff", 177);
	set_skill("unarmed", 139);
	map_skill("magic", "essencemagic");
	map_skill("dodge", "notracesnow");
	map_skill("unarmed", "bloodystrike");
	map_skill("staff", "cloudstaff");
	map_skill("parry", "cloudstaff");
	map_skill("force", "bolomiduo");
	map_skill("iron-cloth", "jin-gang");

	set("inquiry", ([
		"格萨尔": "我见过他,有机会还想和他再比试一下.\n",
		"join" 	: "想加入布达拉宫?那就拜师(apprentice)吧!\n",
		"加入"	: "想加入布达拉宫?那就拜师(apprentice)吧!\n",
		"学习"	: "想加入布达拉宫?那就拜师(apprentice)吧!\n"
	]));
	set("pursuer", 1);
	setup();
	carry_object(__DIR__"obj/jiasha")->wear();
	carry_object(__DIR__"obj/staff")->wear();
}

void attempt_apprentice(object ob)
{
	if( find_call_out("do_recruit") != -1 )
		command("say 慢著，一个一个来。");
	else call_out("do_recruit", 2, ob);
}

void do_recruit(object ob)
{
	command("haha");
	command("say 跟着我吧!\n");
	command("recruit " + ob->query("id") );
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "lama");
}

