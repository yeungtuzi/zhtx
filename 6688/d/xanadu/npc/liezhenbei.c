#include <ansi.h>
int do_poison();

inherit "/std/char/doomnpc";


void create()
{
	object sword;

	set_name("烈震北", ({ "lie zhenbei","lie","zhenbei"}) );
	set("long",@LONG
	他高瘦笔直、傲然挺立，自有一股书香世家的气质．苍白的脸带着浓烈的
书卷气，看上去很年青，但两鬓偏已斑自，他的儒服两袖高高捋趄，露出雪白的手臂，
手十指尖长，尤胜女孩儿家的手。尤其使人注目的是他耳朵上挟着一根银光闪闪长若
五寸的针，当然是他名震天下的「华陀针」。
LONG
	 );

	set("title",MAG"毒医"NOR);
	set("max_gin", 1000);
	set("max_kee", 3000);                    
	set("max_sen", 1000);
	set("max_force",5000); 
	set("force",10000);
	set("force_factor",250);     
	set("combat_exp",69999999);
	set("cor",100);
	set("cps",100);           
	set("spi",100);
	set("age",65);

	set_skill("mantian-huayu", 220);
	set_skill("dodge", 220);
	set_skill("taxue-wuhen",220);
	set_skill("parry", 220); 
	set_skill("throwing",220);
	set_skill("force",220);
	set_skill("tangmen-xinfa",220);
	set_skill("dugong",250);                          
	set_skill("literate",250);
        set_skill("tangshi-jian",220);
        set_skill("sword",220);

	map_skill("force","tangmen-xinfa");
        map_skill("sword","tangshi-jian");
	map_skill("throwing","mantian-huayu");
	map_skill("parry","mantian-huayu");
	map_skill("dodge","taxue-wuhen");
	map_skill("move","taxue-wuhen");

//	prepare_skill("claw","spicyclaw");
	set_temp("apply/attack",50);
/*
	set("chat_chance",3);
        set("chat_msg_combat", ({
		"浪翻云凝视着窗外的明月，姿态悠闲之极。\n",
		"浪翻云举起盛满了清溪流泉的酒壶喝了一大口，笑道：痛快，痛快！\n"
        }) );
*/
	set("chat_chance_combat",90);
        set("chat_msg_combat", ({
		(: do_poison :),
                (: perform_action,"sword.huihuan" :),
        }) );

	setup();

	carry_object(__DIR__"obj/huatuozhen")->wield();
        carry_object("/d/tangmen/obj/huixuanbiao");
	carry_object("/d/tangmen/obj/wuyingdu")->set_amount(100);
        add_money("tenthousand-cash",1);
        if(random(10)>2) carry_rnd_equip(3,5);	
}                          

void init()
{
        set("shen",-500000);
	return;
}
                             
int killed_enemy(object ob)
{
	command("sigh");
}                                 

int do_poison()
{
	object victim;

      if( !(victim=select_opponent()) ) return 1;
	                        
        if( victim->query_condition("tm_poison") > 80 )
	{
		command("exert quickpoison "+victim->query("id"));
	}                                             
	else
	{
		command("poison "+victim->query("id"));
	}
        return 1;
}                                                                        

