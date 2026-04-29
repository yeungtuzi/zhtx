// black dragon

#include <ansi.h>
#include <weapon.h>

inherit WHIP;
inherit F_UNIQUE;

void create()
{
	set_name( BLK "黑水伏蛟" NOR, ({ "dragonwhip", "black dragon", "whip" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("long", "这是「花紫会」龙头的信物，名镇漠南的「黑水伏蛟」。据说是由天蚕丝,黑鲛皮和银木乌藤编成的,威力极强。\n");
		set("unpawnable",1);
		set("value", 8000);
		set("material", "dragonwhip");
		set("wield_msg", "$N将$n抽出在手,四周顿时充满了无边的杀气。\n");
		set("unwield_msg", "$N将$n一抖,$n宛若一条灵蛇般缠绕在手臂上。\n");
		set("replica_ob", __DIR__"fake_whip");
		set("weapon_prop/attack", 3);
	}

          init_whip(110);
	setup();
}
