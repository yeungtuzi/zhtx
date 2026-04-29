// /d/xizang/class/budala/npc/smith.c

#include <ansi.h>

inherit NPC;

string ask_me();

void create()
{
        set_name("铁匠", ({"black smith", "smith", "tie jiang" }));
        set("long", "这是一个普通的铁匠,长年打铁,肌肉发达,但不会武功.\n");
        set("gender", "男性");
        set("attitude", "peaceful");
        set("age", 37);
        set("str", 37);
        set("max_kee", 500);
        set("max_gin", 300);
        set("combat_exp", 10);
        set("score", 1);
	set("inquiry", ([
		"兵器" : (: ask_me :),
		"weapon" : (: ask_me :)
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
        ob=new(__DIR__"obj/staff");
        ob->move(me);
        return "这位"+RANK_D->query_respect(me)+
                ",兵器已经打好了,请看看是否趁手合用?";
}
