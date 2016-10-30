#include <string.h>
#include <3ds.h>
#include <stdio.h>

int main()
{
	gfxInitDefault();
	//gfxSet3D(true); // uncomment if using stereoscopic 3D
   consoleInit(GFX_TOP, NULL);
   
   printf("Ryan Corcoran's 3DS Rebooter v1.0...\n\n");
   printf("Press START to reboot");

	// Main loop
	while (aptMainLoop())
	{
		gspWaitForVBlank();
		hidScanInput();

		u32 kDown = hidKeysDown();
		if (kDown & KEY_START){
			//reboot
         aptOpenSession();
         APT_HardwareResetAsync();
         aptCloseSession();
      }

		// Flush and swap framebuffers
		gfxFlushBuffers();
		gfxSwapBuffers();
	}

	gfxExit();
   
	return 0;
}