// shoutao.c
#include <armor.h>
#include <ansi.h>

inherit HANDS;   
inherit F_UNIQUE;

void create()
{
        set_name( "白金手套", ({ "baijin shoutao", "shoutao" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "双");
                set("long", "这是一双白金丝编的手套，刀枪不入。\n");
                set("value", 6000);
                set("material", "hands");
                set("armor_prop/armor", 5);
                set("armor_prop/defense",10);
        }
        setup();
}

int dispersion_damage(object killer,object victim,int damage)
{
	object weap;
	int ap,dp;     
	string s_type,weap_name;
	
	if( !objectp(weap=killer->query_temp("weapon")) )
	{   
		return 0;
	}		  
	//太坚硬锋利的抓不动
	//if( weap->query("rigidity") > 50000 ) return 0;
	message_vision(HIY"正在$N"+weap->name()+"正要及体之际，$n突然一翻手抓住了"+weap->name()+"！\n"NOR,killer,victim);
	s_type = weap->query("skill_type");      
	
	ap = weap->query("rigidity") + killer->query_str()*killer->query_str() + killer->query("force")*5;
	dp = victim->query("force")*5 + victim->query_str()*victim->query_str();
	//抓住了，攻击没造成效果	
	if( random(ap+dp) < dp )
	{
		if( (s_type == "sword" || s_type == "blade") && weap->query("rigidity") < 50000  )
		{
	  		message_vision(HIY"只见$n轻轻巧巧的运劲一拗，“啪”的一声，$N手里的"+weap->name()+"已经断成两截！\n"NOR,killer,victim);
                        weap_name = weap->query("name");
                        weap->unequip();
                        weap->move(environment(killer));
                        weap->set("name", "断掉的" + weap->query("name"));
                        weap->set("value", 0);
                        weap->set("weapon_prop", 0);
                        weap->set("long", weap->query("long")+"可是，现在却已经断为两截，不知道还有什么用处。\n");
                        killer->reset_action();		
		}               
		return damage;  	
	}
	//没抓住，伤害增加
	message_vision(HIY"但是$N运足真力，"+weap->name()+"脱离了$n的掌握，余势更猛！\n"NOR,killer,victim);	
	return -damage/4;	
}	
int wear()
{
      if( this_player()->query("family/family_name") != "古墓派" )
          {        return notify_fail("这手套要配合古墓的功夫才能发挥出效果。\n");}                                                         ;
          return ::wear();
}
