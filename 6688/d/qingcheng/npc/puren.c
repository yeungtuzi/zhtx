/* buren.c */

inherit NPC;

void create()
{
        set_name("仆人", ({ "puren" }) );
        set("gender", "男性" );
        set("age", 21);
        set("long","他是恶少的家仆,经常仗着恶少的势力为凶作歹 . \n");
        set("combat_exp", 500);
            set("rank_info/respect", "家仆");
       

        set_skill("unarmed",10);
                     
  //      carry_object("/obj/cloth")->wear();
        setup();
}
