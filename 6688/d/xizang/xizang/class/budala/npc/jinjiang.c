// /d/xizang/class/budala/npc/jinjiang.c

#include <ansi.h>

inherit NPC;

string ask_me();
string ask_me2();

void create()
{
        set_name("金匠", ({"jin jiang", "jiang" }));
        set("long", "这是一个年老的金匠,满脸都是皱纹.\n");
        set("gender", "男性");
        set("attitude", "peaceful");
        set("age", 62);
        set("str", 20);
        set("max_kee", 400);
        set("max_gin", 400);
        set("combat_exp", 10);
        set("score", 1);
	set("inquiry", ([
		"护身符" : (: ask_me :),
		"佛像"	 : "佛像请到山下店里购买.\n",
		"戒指"	 : (: ask_me2 :)
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
        return "活佛祝福过的护身符只能授予本宫弟子.\n";
        ob=new(__DIR__"obj/amulet");
        ob->move(me);
        return "这个护身符交给你了,请好好保管.\n";
}

string ask_me2()
{
	object me,ob;
        me=this_player();
	if ((string)me->query("marks/老鼠") != "流浪猫")
		return "这种俗物还是到山下店里去买吧.\n";
	ob=new(__DIR__"obj/ring");
	ob->move(me);
	me->delete("marks/老鼠");
	return "这个戒指交给你了,请好好保管.\n";
}
