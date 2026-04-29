// swamp1.c
// by meteoric
#include "ansi.h"
inherit "/ldg/std/dyna_room.c";
void create()
{
	set("short", "沼泽地");
	set("long", BLK@LONG
你身处一片沼泽之中,周围雾气蒙蒙,一股腥气扑鼻而来,举步踏到的尽是矮树长草，
每走一步，荆棘都钩刺到小腿，你走了一阵，四周更是漆黑一团，纵然尽力睁大
眼睛，也是难以见物
LONG NOR);
	
	
	setup();
}