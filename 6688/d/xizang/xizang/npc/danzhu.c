// /d/xizang/npc/danzhu.c

inherit NPC;

void create()
{
        set_name("丹珠", ({ "danzhu", "kid" }) );
        set("gender", "女性" );

        set("age", 9);
        set("long", "她是藏族小女孩丹珠,她是次仁多吉的女儿.\n");
        set("combat_exp", 20);
        set("per", 25);
        setup();
        carry_object(__DIR__"obj/zcloth")->wear();
}
