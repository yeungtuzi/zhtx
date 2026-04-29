// /d/xizang/class/budala/npc/painter.c

#include <ansi.h>

inherit NPC;

string ask_me();

void create()
{
        set_name("画匠", ({"painter", "hua jiang", "jiang" }));
        set("long", "这是一个布达拉宫的画匠.\n");
        set("gender", "男性");
        set("attitude", "peaceful");
        set("age", 39);
        set("str", 24);
        set("max_kee", 300);
        set("max_gin", 300);
        set("combat_exp", 10);
	set_skill("drawing", 100);
        set("score", 1);
	set("inquiry", ([
		"学画" : "这工作又累又没什么钱赚,还是算了吧",
		"江南" : "我本是江南人,也不知道哪年可以回家",
		"回家" : "你若要去中原,可不可以到杭州西湖畔的画店看看?",
		"画店" : "我曾是那里的学徒,不知道师父他们还好吗?",
		"画像" : (: ask_me :),
		"picture" : (: ask_me :)
	]));
        setup();
        carry_object(OBJ_DIR"cloth")->wear();
}

string ask_me()
{
	object me,ob;
        me=this_player();
	if(!objectp(ob=present("picture", me)) ||
		(string)ob->query("character") != "小梅")
	return "这位"+RANK_D->query_respect(me)+ 
		"的尊容,恰可作本宫的一位护法神将\n";
	if(me->query("marks/xiaomei"))
		return "这位"+RANK_D->query_respect(me)+
			"和这位姑娘很熟吗?她现在还好吧?\n";
	if(me->query("marks/mei_pic"))
		return "这位"+RANK_D->query_respect(me)+
			"我已经和你说过了,只在江南一家画店见过类似的画像.\n";
	me->set("marks/mei_pic");
	command("sigh");
	return "我在江南一家画店见过类似的画像,不过手法略有不同....\n"+
		"总之作者的画技比我高多了,唉.....\n";
}
