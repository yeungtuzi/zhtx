//NPC:/d/xueshan/npc/dragon3.c 
//by tlang for 旋芒宝剑
         
#include <ansi.h>

inherit NPC;

int change_skill(object me);

void create()
{
	set_name(RED"九头火龙"NOR, ({ "fire dragon", "dragon"}));
	set("race", "野兽");
	set("age", 98);
	set("gender", "雄性");
	set("long", "一头张牙舞爪的龙，看上去不好惹。\n");
	set("attitude", "peacefully");

	set("limbs", ({ "头部", "身体", "尾巴","前脚", "後脚"}) );
        set("verbs", ({ "bite","claw" }) );

	set("str", 40);
	set("dex", 40);

	set("max_kee",3000);
	set("max_gin",1500);
	set("max_sen",1500);

	set("combat_exp", 3000000);
	set("shen_type", 0);

	set_skill("unarmed", 150);
	set_skill("dodge", 200);
	set_skill("parry", 200);

	set("no_get",1);
	setup();
}

void init()
{
	object ob;

	::init();
        if( interactive(ob = this_player()) ) {
	remove_call_out("greeting");
	call_out("greeting",1,ob);
	}
}

void greeting(object ob)
{
	object me=this_object();

	int my_exp, ob_exp;
	int ob_force;

	ob_exp=ob->query("combat_exp");
	my_exp=me->query("combat_exp");	
  	ob_force=ob->query("max_force");
	if( !ob || environment(ob) != environment() ) return;
	me->set("combat_exp",ob_exp*2);
	me->set("max_force",ob_force*2);
	me->set("force",ob_force*2);

	command("heng");
	ob->start_busy(2);
	call_out("change_skill",1,me);
}


//changed from disc's shashou
int change_skill(object me)
{
	object ob=this_player();

	mapping skill_status, map_status;
        string *sname, *mname;
	int i,temp;

	/*delete and copy skills */
	if ( mapp(skill_status = me->query_skills()) ) {
                skill_status = me->query_skills();
                sname  = keys(skill_status);

                temp = sizeof(skill_status);
                for(i=0; i<temp; i++) {
                        me->delete_skill(sname[i]);
                }
        }

	if ( mapp(skill_status = ob->query_skills()) ) {

                skill_status = ob->query_skills();
                sname  = keys(skill_status);
                
	        for(i=0; i<sizeof(skill_status); i++) {
                me->set_skill(sname[i], skill_status[sname[i]]*2+random(10) );
                }
	}
	/* delete and copy skill maps */

        if ( mapp(map_status = me->query_skill_map()) ) {
                mname  = keys(map_status);

                temp = sizeof(map_status);
                for(i=0; i<temp; i++) {
                        me->map_skill(mname[i]);
                }
        }

        if ( mapp(map_status = ob->query_skill_map()) ) {
                mname  = keys(map_status);

                for(i=0; i<sizeof(map_status); i++) {

                        me->map_skill(mname[i], map_status[mname[i]]);
                }
        }

	kill_ob(ob);
		return 1;
}


