//by zephyr
inherit NPC;
inherit F_MASTER;

#include <ansi.h>
void create()
{
        set_name("柳若松", ({ "liu ruosong","liu"}) );
        set("long",YEL@LONG
他本是名满天下的“岁寒三友”中的“青松剑客”。
也是武当山玄真观，天一真人门下唯一的俗家弟子。
但后来为了一把叫做“小楼一夜听风雨的”的神刀，他
毒杀了丁鹏的仆从铜驼，虏走了丁鹏的儿子。有此刀
在手，加上魔教的神刀斩，天下几乎无人是他的对手。
只有一个人，一个会让他做恶梦的人，他没有把握战胜
那个人就是丁鹏。
LONG NOR
         );

        set("title",YEL"神刀山庄"WHT"庄主"NOR);
        set("age", 50);
        //set advanced skills
        create_family("万松山庄", 7, "庄主");

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
        (: exert_function, "recover" :),
        }) );

        set_skill("force", 400);
        set_skill("strike", 400);
        set_skill("sword", 400);
        set_skill("blade", 400);
        set_skill("parry", 400);
        set_skill("dodge", 400);
        set_skill("perception", 400);
                
        set_skill("taiji-shengong", 280);
        set_skill("celestrike", 400);
        set_skill("spring-blade", 400);
        set_skill("pyrobat-steps", 400);
        map_skill("force", "taiji-shengong");
        map_skill("strike","celestrike");
        prepare_skill("strike", "celestrike");
        map_skill("blade", "spring-blade");
        map_skill("dodge", "pyrobat-steps");
 
    set("shen_type",-1);
    set("skill_mark/spring-blade",1);

        
        set("attitude", "peaceful");
        set("combat_exp", 20000000);
        set("shen_type",-1);

        set("str", 100);
        set("int", 100);
        set("spi", 100);
        set("cor", 100);
        set("cps", 100);                       
        set("per", 30);
        set("con", 100);
        set("bln",100);
        set("no_get",1);

        set("atman", 1000);
        set("max_atman", 1000);

        set("force", 20000);
        set("max_force", 10000);
        set("force_factor", 300);

        set("mana", 5000);
        set("max_mana", 5000);

        set("max_kee",100000);
        set("max_gin",20000);
        set("max_sen",20000);

        set_temp("apply/defense",100);
        set_temp("apply/armor_vs_force",1000);
        set_temp("apply/armor",1000);
        
        set("bellicosity",1000);
        set("dingpeng_enemy",1);

    setup();

        carry_object("/obj/cloth/cloth")->wear();
        carry_object(__DIR__"moonblade")->wield();
        set("bellicosity",1000);
}                          



void chat()
{
	object me, liu;
	int fighting,hurt,force_fac,i, all;
	object *enemy, victim, weapon, po_weapon, taken_weapon;

	me = this_object();
	if( !environment(me) ) return 0;
	fighting = me->is_fighting();
	

	if( query("eff_kee")<query("max_kee")*70/100)     
	{
		force_fac = query("force_factor");
		if(fighting) command("halt");
		hurt = query("max_kee")-query("eff_kee");
		hurt /= 100;
		while( hurt-- )
		command("exert heal");
		set("force_factor",force_fac);
	}     
	
	if(query("sen")<(query("eff_sen")*70/100))
	command("exert refresh");
	if(query("kee")<(query("eff_kee")*70/100))
	command("exert recover");
	if(query("gin")<(query("eff_gin")*70/100))
	command("exert regenerate");
	
	if (is_fighting())
	{
		int f= query("force_factor");
		enemy = me->query_enemy();
		all = sizeof(enemy);

		if (f<300)
		{
			set("force_factor",300);
		}

		if(!objectp(query_temp("weapon")))
		{
			weapon=new(__DIR__"moonblade");
			//打破在地
			po_weapon = present("moon blade", environment());
			//被夺兵器
			for(i=0;i<all;i++)
			{
				victim = enemy[i];
				taken_weapon = present("moon blade", victim);
				if ( objectp(taken_weapon) )
				{
					destruct(taken_weapon);
					message_vision(CYN"柳若松蓦地和身向"+victim->name()+"扑出，左手手指已搭住小楼一夜听春雨的刀柄。\n"NOR, environment());
					message_vision(CYN"\n"+victim->name()+"猛吃一惊，正待反击，"+name()+"右手食中二指倏取"+victim->name()+"的双目，同时左足翻起，已将刀身压住\n"NOR, environment());
					message_vision(CYN"\n"+victim->name()+"为保眼珠，只得松手放开神刀。\n"NOR, environment());
				}
			}

			weapon->move(this_object());
			if ( objectp ( po_weapon ) )
			{
				destruct(po_weapon);
				message_vision(CYN"柳若松信手一抄，从地上拿起了那把已经断掉的圆月弯刀，轻轻一抖。\n"NOR, environment());
				message_vision(WHT"白光一闪间，神刀居然完好无损了！\n"NOR, environment());
			}
			command("heng");
			command("say 难道不知道我手上这把圆月弯刀的神奇之处吗？今天让你见识见识！");
			command("wield "+weapon->query("id"));
		}
	}

	::chat();

}

int killed_enemy(object ob)
{
	if ( !query_temp("kill_dingpeng") )
	{
		command("heng");
		command("say 不知死活的东西，竟敢在太岁头上动土！");
		add("bellicosity",10000);
		return 0;
	}

	if ( living(this_object()))
		call_out("leave",1);
	if (!living(this_object()))
		call_out("leave",100);
	return 1;
}                 

void die()
{
        object me, blade, eblade,killer;
        me=this_object();
		killer = query_temp("last_damage_from");
		blade = query_temp("weapon");
		eblade = killer->query_temp("weapon");
		if( objectp(killer) && environment() && killer->query("id")=="ding peng") 
        {
			killer->set_temp("dingpeng/kill_liuruosong",1);
        }
		if ( objectp(blade) && objectp(eblade) && eblade->query("chubi") && killer->query("id")=="ding peng" )
		{
			message("vision", CYN"\n\n丁鹏忽然低吼一声，举起手中木刀直砍下来，正是魔教“神刀斩”\n", environment());
			message("vision", CYN"\n柳若松冷笑一声，也以同样的招式回击\n", environment());
			message("vision", CYN"\n柳若松出手较慢，但他手中却是百坚不摧的圆月弯刀，他有绝对的信心胜过丁鹏\n"NOR, environment());
			message("vision", CYN"\n两刀相触时，柳若松忽然想起了那柄木刀的珍奇，不免顿了一顿\n"NOR, environment());
			message("vision", CYN"\n这本来就是丁鹏所预期的，他所要争取的是速度。\n"NOR, environment());
			message("vision", CYN"\n刀与刀一触即分，木刀自然无法胜过神刀的，被劈成了两片。\n"NOR, environment());
			message("vision", CYN"\n但是丁鹏的攻势却没断，两片木刀直下，柳若松的人分成了三片。\n"NOR, environment());
		}
        ::die();
}
int leave()
{
	command("laugh");
	command("say 丁鹏你这个老小子，自命天下刀法第一，到头来，还不是死在我柳若松刀下！\n");
	command("haha");
	command("say "+"自此我神刀一出，天下谁与争锋！！\n");
	command("bye");
	message("vision", CYN"\n柳若松飘然离去。\n"NOR, environment());
	destruct(this_object());
}
