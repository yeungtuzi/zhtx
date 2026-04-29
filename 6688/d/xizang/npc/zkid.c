// /d/xizang/npc/zkid.c

inherit NPC;

void create()
{
        set_name("藏族小孩", ({ "kid", "xiaohai", "hai" }) );
        if (random(30) > 15)
                set("gender", "女性" );
                else set("gender", "男性");

        set("age", 1+random(16));
        set("long", "一个普通的藏族小孩子.\n");
        set("combat_exp", 7+random(6)*100);
        set("per", 10+random(20));
        set("inquiry", ([
               "宝藏": "真的有宝藏就好了.\n",
           "昆仑之墟": "昆仑之墟是诸神居住的地方.\n",
        ]) );
        set("attitude", "friendly");
        setup();
        carry_object(__DIR__"obj/zcloth")->wear();
}
