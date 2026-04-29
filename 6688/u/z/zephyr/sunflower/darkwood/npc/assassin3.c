//by zephyr

#include <ansi.h>
inherit "/u/z/zephyr/sunflower/npc/advance_npc";
void create()
{
	int lvl,t;
	set("level",6);
	set_name(HIG"绿衣刺客"NOR, ({ "lvyi cike","assassin","cike"}) );
	set("long",BLK@LONG
他穿着紧身的绿衣，以绿巾蒙面，身法快如急风，轻如飞絮，
手中一柄长枪如蛟龙出海，枪尖绿光闪烁，必浸有奇毒。
LONG NOR
	 );
	set("title",HIB"龙枪"NOR);
	set("age",21);
	set("percmd", "exert powerup" );
	//set advanced skills
	lvl=query("level");
	t=230+(6-lvl)*25;
	set_skill("yangjia-qiang", t+random(10));
	set_skill("huntian-qigong",t+random(10));
	set_skill("xianyun",t+random(10));
	set_skill("iron-cloth",t+random(10));
	set_skill("perception", t+random(10));
	set_skill("jiuyin",t+random(10));


	map_skill("force","huntian-qigong");
	map_skill("parry","yangjia-qiang");
	map_skill("spear","yangjia-qiang");
	map_skill("dodge","xianyun");
	map_skill("move","xianyun");
	map_skill("iron-cloth","jiuyin");


	setup();
	carry_object("/obj/cloth/cloth")->wear();
	carry_object(__DIR__"obj/poisonspear")->wield();
	set("weapon_type","spear");

}                          

        
int hit_ob(object me, object ob, int damage)
{
	int n;
	n=(int)ob->query_condition("shw_poison");
	ob->apply_condition("shw_poison", 3+n);
	tell_object(ob, HIG "你觉得伤口一阵麻痒！\n" NOR );
}

                     
int killed_enemy(object ob)
{
	command("heihei");
}                 
                     
int accept_kill(object me)
{
        object ob;
        if(ob=present("qingyi cike",environment()))
        {
                ob->kill_ob(me);
                me->kill_ob(ob);
        }
        if(ob=present("heiyi cike",environment()))
        {
                ob->kill_ob(me);
                me->kill_ob(ob);
        }
        return 1;
}
