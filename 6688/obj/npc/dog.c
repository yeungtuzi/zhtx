// /obj/npc/dog.c


inherit NPC;

void create()
{
        set_name("警犬", ({ "police dog" ,"dog" }) );
        set("race", "野兽");
        set("age", 4);
        set("long", "一只受过专门训练的警犬,不仅形体比通常的狗大很多,而且\n"+
"肌肉发达有力,一般壮汉绝对不是它的对手.\n");
        set("attitude", "heroism");
        set("str", 50);
        set("cor", 50);
        set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("combat_exp", 60000);

        setup();
}
