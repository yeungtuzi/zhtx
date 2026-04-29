// /d/xizang/class/budala/npc/tailor.c

#include <ansi.h>

inherit NPC;

string ask_me();

void create()
{
        set_name("裁缝", ({"tailor", "cai feng" }));
        set("long", "这是一个布达拉宫的裁缝.\n");
        set("gender", "男性");
        set("attitude", "peaceful");
        set("age", 51);
        set("str", 12);
        set("max_kee", 300);
        set("max_gin", 300);
        set("combat_exp", 10);
        set("score", 1);

	set("inquiry", ([
		"衣服" : (: ask_me :),
		"cloth": (: ask_me :)
	]));
        setup();
        carry_object(OBJ_DIR"cloth")->wear();
}

string ask_me()
{
	object me,ob;
	mapping ob_fam;

	me=this_player();
	if (!mapp(ob_fam = me->query("family")) || 
		ob_fam["family_name"] != "布达拉宫")
	return "这位"+RANK_D->query_respect(me)+ 
		"与本宫素无来往，不知此话从何谈起？";
	ob=new(__DIR__"obj/jiasha");
	ob->move(me);
	return "这位"+RANK_D->query_respect(me)+
		",衣服已经做好了,请拿去穿吧.";
}
