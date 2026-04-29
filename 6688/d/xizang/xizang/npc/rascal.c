// /d/xizang/npc/rascal.c

inherit NPC;

void create()
{
        set_name("小流氓", ({ "xiao liumang", "liumang", "rascal" }) );
        set("gender", "男性" );
        set("age", 10+random(15));
        set("long", "一个不务正业的小家伙.\n");
        set("combat_exp", 100+10*random(50));
        set("str", 20+random(11));
        setup();
        set("chat_chance", 15);
        set("chat_msg", ({
                (: random_move :)
        }) );
        set("inquiry", ([
                "宝藏" : "那只是一个传说,没有人能找得到.\n",
                "传说" : "好象是叫作什么昆仑之墟的,喇嘛们或许知道.\n",
	      "夜叉王" : "他武功盖世,是我们的老大.\n"
        ]) );
	setup();
	carry_object(__DIR__"obj/zcloth")->wear();
}

int accept_fight(object me)
{
        command("say " + RANK_D->query_respect(me) + 
"饶命！小的这就离开！\n");
        return 0;
}
