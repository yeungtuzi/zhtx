//by zephyr

#include <ansi.h>
inherit "/u/z/zephyr/sunflower/npc/advance_npc";
void create()
{
	int lvl,t;
	set("level",6);
	set_name(HIM"紫衣刺客"NOR, ({ "ziyi cike","assassin","cike"}) );
	set("long",BLK@LONG
他穿着紧身的紫衣，以紫巾蒙面，身法快如急风，轻如飞絮，
手中一柄长刀挥舞如风，刀刃紫光闪烁，必浸有奇毒。
LONG NOR
	 );
	set("title",HIM"冷月"NOR);
	set("age",21);

	//set advanced skills
	lvl=query("level");
	t=230+(6-lvl)*25;

	set_skill("chaidao-shibalu", t+random(10));
	set_skill("dodge", t+random(10));
	set_skill("parry", t+random(10));
	set_skill("blade",t+random(10));
	set_skill("force",t+random(10));
	set_skill("bat-steps",t+random(10));
	set_skill("huntian-qigong",t+random(10));
	set_skill("iron-cloth",t+random(10));
	set_skill("jiuyin",t+random(10));
	set_skill("perception", t+random(10));
	set("percmd", "exert powerup" );


	map_skill("force","huntian-qigong");
	map_skill("parry","chaidao-shibalu");
	map_skill("move","bat-steps");
	map_skill("dodge","bat-steps");
	map_skill("blade","chaidao-shibalu");
	map_skill("iron-cloth","jiuyin");



	setup();
	carry_object("/obj/cloth/cloth")->wear();
	carry_object(__DIR__"obj/poisonblade")->wield();
	set("weapon_type","blade");
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
        if(ob=present("huangyi cike",environment()))
        {
                ob->kill_ob(me);
                me->kill_ob(ob);
        }
        if(ob=present("chiyi cike",environment()))
        {
                ob->kill_ob(me);
                me->kill_ob(ob);
        }
        return 1;
}
