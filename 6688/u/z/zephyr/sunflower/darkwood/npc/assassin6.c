
//by zephyr

#include <ansi.h>
inherit "/u/z/zephyr/sunflower/npc/advance_npc";
void create()
{
	int lvl,t;
	set("level",6);
	set_name(HIY"黄衣刺客"NOR, ({ "huangyi cike","assassin","cike"}) );
	set("long",BLK@LONG
他穿着紧身的黄衣，以黄巾蒙面，身法快如急风，轻如飞絮，
他的双掌就是他致命的武器。掌心暗暗透出蓝莹莹光芒，显
然练的是毒掌功夫。
LONG NOR
	 );
	set("title",HIY"毒煞"NOR);
	set("age",21);

	//set advanced skills
	lvl=query("level");
	t=230+(6-lvl)*25;


	set_skill("qishang-quan", t+random(10));
	set_skill("dodge", t+random(10));
	set_skill("parry", t+random(10));
	set_skill("cuff",t+random(10));
	set_skill("force",t+random(10));
	set_skill("bat-steps",t+random(10));
	set_skill("huntian-qigong",t+random(10));
	set_skill("iron-cloth",t+random(10));
	set_skill("perception", t+random(10));
	set_skill("jiuyin",t+random(10));
	set("percmd", "exert powerup" );

	map_skill("force","huntian-qigong");
	map_skill("cuff","qishang-quan");
	map_skill("move","bat-steps");
	map_skill("dodge","bat-steps");
	map_skill("parry","qishang-quan");
	map_skill("iron-cloth","jiuyin");
    prepare_skill("cuff", "qishang-quan");


	setup();

	carry_object("/obj/cloth/cloth")->wear();

}                          
 int hit_ob(object me, object ob, int damage)
{
	int n;
	n=(int)ob->query_condition("shw_poison");
	ob->apply_condition("shw_poison", 10+n);
	tell_object(ob, HIG "你觉得伤口一阵麻痒！\n" NOR );
}
                            
int killed_enemy(object ob)
{
	command("heihei");
}                 
                     
                     
int accept_kill(object me)
{
        object ob;
        if(ob=present("ziyi cike",environment()))
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
