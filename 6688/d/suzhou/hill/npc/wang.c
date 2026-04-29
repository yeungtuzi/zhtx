//by tlang
         
#include <ansi.h>
inherit NPC;            

void create()
{
	set_name(HIW"王安石"NOR, ({ "wang anshi", "wang" }));
	set("long", "他曾经三次出任宰相，当真是有真才实学。\n");
	set("gender", "男性");

	set("per", 30);      
	set("int", 32);
        set("age", 55);
    
	set_skill("literate", 200);
	set_skill("leadership", 250);

	set_skill("iron-cloth",100);
	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("parry", 200);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 50);

	set("combat_exp", 3000000);
	set("shen_type", 1);        
	
	setup();
        
	add_money("gold", 10);
	carry_object("/d/suzhou/npc/obj/baishan")->wear();
	carry_object(__DIR__"obj/jchmap");
}                                   

