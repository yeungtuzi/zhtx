//fupishi.c 斧劈石
//by emote
#include <room.h>
inherit ROOM;

void create()
{
	set("short","斧劈石");
	set("long",
@LONG
顺殿后往西有一小门，出门是一巨石，巨是断而为三。巨石上刻有“斧
劈石”。这便是神话故事《宝莲灯》中三圣母被压的地方。从这里沿铁链上
去，在斧劈石下，人钻其内可看到一巨型人模，头、胳膊、乳房、腿等都很
明显，说是三圣母被压在此留下的。这旁边立有一大铁斧，约长两米五左右，
上铸“仙家宝斧，七尺有五，赐予沉香，劈山救母”十六个字。相传三圣母
压在这里之后，生下了沉香，被灵芝大仙送出，交于生父刘玺抚养。等沉香
长大成人之后，刘玺把此事告诉了沉香，沉香立志救母，便投师于霹雳大仙。
艺成之后就持这把天赐宝斧，战胜了舅父二郎神，劈开了西峰，救出母亲，
一家人得以团圆。你可以试一试自己能不能举起这把神斧。

LONG);
        set("exits", ([ /* sizeof() == 2 */
		"east"   : __DIR__"cuiyun",
		]));
        create_door("east", "旧木门", "west", DOOR_CLOSED);
	setup();
	
}

void init()
{
	add_action("do_pick","pick");
	
}

void do_pick(string arg)
{
	object me=this_player();
	object axe;
	if(!arg||arg=="")
	  return notify_fail("你要拔什么？\n");
	if(arg=="axe")
	  {
	  	if((me->query_str()+me->query("max_force"))<70)
	  	   return notify_fail("你运尽了吃奶的劲，结果神斧纹丝不动。\n");
		else 
		if(me->query("force")>3000)
		{
			if(!random(15))
			   {
				axe=new(__DIR__"obj/sharpaxe.c");
				axe->move(me);
				set("long",
@LONG
顺殿后往西有一小门，出门是一巨石，巨是断而为三。巨石上刻有“斧
劈石”。这便是神话故事《宝莲灯》中三圣母被压的地方。从这里沿铁链上
去，在斧劈石下，人钻其内可看到一巨型人模，头、胳膊、乳房、腿等都很
明显，说是三圣母被压在此留下的。这旁边立有一大铁斧，约长两米五左右，
上铸“仙家宝斧，七尺有五，赐予沉香，劈山救母”十六个字。相传三圣母
压在这里之后，生下了沉香，被灵芝大仙送出，交于生父刘玺抚养。等沉香
长大成人之后，刘玺把此事告诉了沉香，沉香立志救母，便投师于霹雳大仙。
艺成之后就持这把天赐宝斧，战胜了舅父二郎神，劈开了西峰，救出母亲，
一家人得以团圆。现在神斧已经被拔出来了，这里空荡荡的。
LONG);
				
				return notify_fail("你大喝一声“开”，结果神斧被你应声拔起。\n");	   	
			   
			   }
			   me->add("force",-500);
			   return notify_fail("你大喝一声“开”，结果神斧还是纹丝不动。\n");
		}	  	   
	  	else 
	  	return notify_fail("你的内力不够，拔不动神斧。\n");
	  
	  }
	   
	return notify_fail("你要拔什么？\n");
}
