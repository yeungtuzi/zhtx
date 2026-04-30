// reboot.c

#include <login.h>
#include <obj.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	// 2026-04-30: unused variable commented out
	// string wiz_status;
	object npc;

	if( me != this_player(1) ) return 0;
	
	if( wiz_level(me) < 4 && raw_wiz_level(me) < 4 )
		return notify_fail("只有 (arch) 以上的巫师才能重新启动" + MUD_NAME + "\n");

	seteuid(getuid());

	npc = new(NPC_DEMOGORGON);
	npc->move(START_ROOM);
	npc->start_shutdown();

	write("Ok。\n");

	return 1;
}
