// youngman.c

#include <ansi.h>
inherit NPC;

int accept_object(object ob,object what);

void create()
{
        set_name("贵公子", ({ "young man","man" }) );
        set("long", "一个相貌俊美的年轻贵公子正优雅地欣赏着堤两边的景物。\n");
        set("age", 22);
        set("attitude", "peaceful");
        set("combat_exp", 2500);
        set("env/wimpy", 50);
        set("str", 20);
        set("cor", 26);
        set("cps", 26);
        set("per", 29);
        set("inquiry", ([
                "name": "在下姓二百，单名一个武字，不知阁下如何称呼？",
                "here": "这里是杭州，您是外地来的吧？",
                "trouble": ({
                        (: command, "hmm" :),
                        "我没有什么烦恼。。。pp\n",
                        }),
        ]) );
        set_skill("dodge", 40);
        set_skill("unarmed", 40);
        set_skill("parry", 40);
        set_skill("sword", 40);
        setup();
        carry_object("/d/choyin/npc/obj/hat")->wear();
        carry_object("/obj/cloth")->wear();
        carry_object("/obj/weapon/longsword")->wield();
}

int accept_object(object ob,object what)
{
 	command("thank "+ob->query("id"));
        	return 1;       
}
