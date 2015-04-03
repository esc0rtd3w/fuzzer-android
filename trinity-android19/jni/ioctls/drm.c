#include <inttypes.h>
#include <stdlib.h>
#include <linux/ioctl.h>

#include "shm.h"
#include "utils.h"
#include "ioctls.h"
#include "ioctl_types.h"


#ifdef USE_DRM


static const struct ioctl drm_ioctls[] = {
	/* drm/drm.h */
  IOCTL(DRM_IOCTL_VERSION, 0, 0),
  IOCTL(DRM_IOCTL_GET_UNIQUE, 0, 0),
  IOCTL(DRM_IOCTL_GET_MAGIC, 0, 0),
  IOCTL(DRM_IOCTL_IRQ_BUSID, 0, 0),
  IOCTL(DRM_IOCTL_GET_MAP, 0, 0),
  IOCTL(DRM_IOCTL_GET_CLIENT, 0, 0),
  IOCTL(DRM_IOCTL_GET_STATS, 0, 0),
  IOCTL(DRM_IOCTL_SET_VERSION, 0, 0),
  IOCTL(DRM_IOCTL_MODESET_CTL, 0, 0),
  IOCTL(DRM_IOCTL_GEM_CLOSE, 0, 0),
  IOCTL(DRM_IOCTL_GEM_FLINK, 0, 0),
  IOCTL(DRM_IOCTL_GEM_OPEN, 0, 0),
#ifdef DRM_IOCTL_GET_CAP
  IOCTL(DRM_IOCTL_GET_CAP, 0, 0),
#endif
  IOCTL(DRM_IOCTL_SET_UNIQUE, 0, 0),
  IOCTL(DRM_IOCTL_AUTH_MAGIC, 0, 0),
  IOCTL(DRM_IOCTL_BLOCK, 0, 0),
  IOCTL(DRM_IOCTL_UNBLOCK, 0, 0),
  IOCTL(DRM_IOCTL_CONTROL, 0, 0),
  IOCTL(DRM_IOCTL_ADD_MAP, 0, 0),
  IOCTL(DRM_IOCTL_ADD_BUFS, 0, 0),
  IOCTL(DRM_IOCTL_MARK_BUFS, 0, 0),
  IOCTL(DRM_IOCTL_INFO_BUFS, 0, 0),
  IOCTL(DRM_IOCTL_MAP_BUFS, 0, 0),
  IOCTL(DRM_IOCTL_FREE_BUFS, 0, 0),
  IOCTL(DRM_IOCTL_RM_MAP, 0, 0),
  IOCTL(DRM_IOCTL_SET_SAREA_CTX, 0, 0),
  IOCTL(DRM_IOCTL_GET_SAREA_CTX, 0, 0),
  IOCTL(DRM_IOCTL_SET_MASTER, 0, 0),
  IOCTL(DRM_IOCTL_DROP_MASTER, 0, 0),
  IOCTL(DRM_IOCTL_ADD_CTX, 0, 0),
  IOCTL(DRM_IOCTL_RM_CTX, 0, 0),
  IOCTL(DRM_IOCTL_MOD_CTX, 0, 0),
  IOCTL(DRM_IOCTL_GET_CTX, 0, 0),
  IOCTL(DRM_IOCTL_SWITCH_CTX, 0, 0),
  IOCTL(DRM_IOCTL_NEW_CTX, 0, 0),
  IOCTL(DRM_IOCTL_RES_CTX, 0, 0),
  IOCTL(DRM_IOCTL_ADD_DRAW, 0, 0),
  IOCTL(DRM_IOCTL_RM_DRAW, 0, 0),
  IOCTL(DRM_IOCTL_DMA, 0, 0),
  IOCTL(DRM_IOCTL_LOCK, 0, 0),
  IOCTL(DRM_IOCTL_UNLOCK, 0, 0),
  IOCTL(DRM_IOCTL_FINISH, 0, 0),
#ifdef DRM_IOCTL_PRIME_HANDLE_TO_FD
  IOCTL(DRM_IOCTL_PRIME_HANDLE_TO_FD, 0, 0),
#endif
#ifdef DRM_IOCTL_PRIME_FD_TO_HANDLE
  IOCTL(DRM_IOCTL_PRIME_FD_TO_HANDLE, 0, 0),
#endif
  IOCTL(DRM_IOCTL_AGP_ACQUIRE, 0, 0),
  IOCTL(DRM_IOCTL_AGP_RELEASE, 0, 0),
  IOCTL(DRM_IOCTL_AGP_ENABLE, 0, 0),
  IOCTL(DRM_IOCTL_AGP_INFO, 0, 0),
  IOCTL(DRM_IOCTL_AGP_ALLOC, 0, 0),
  IOCTL(DRM_IOCTL_AGP_FREE, 0, 0),
  IOCTL(DRM_IOCTL_AGP_BIND, 0, 0),
  IOCTL(DRM_IOCTL_AGP_UNBIND, 0, 0),
  IOCTL(DRM_IOCTL_SG_ALLOC, 0, 0),
  IOCTL(DRM_IOCTL_SG_FREE, 0, 0),
  IOCTL(DRM_IOCTL_WAIT_VBLANK, 0, 0),
  IOCTL(DRM_IOCTL_UPDATE_DRAW, 0, 0),
  IOCTL(DRM_IOCTL_MODE_GETRESOURCES, 0, 0),
  IOCTL(DRM_IOCTL_MODE_GETCRTC, 0, 0),
  IOCTL(DRM_IOCTL_MODE_SETCRTC, 0, 0),
  IOCTL(DRM_IOCTL_MODE_CURSOR, 0, 0),
  IOCTL(DRM_IOCTL_MODE_GETGAMMA, 0, 0),
  IOCTL(DRM_IOCTL_MODE_SETGAMMA, 0, 0),
  IOCTL(DRM_IOCTL_MODE_GETENCODER, 0, 0),
  IOCTL(DRM_IOCTL_MODE_GETCONNECTOR, 0, 0),
  IOCTL(DRM_IOCTL_MODE_ATTACHMODE, 0, 0),
  IOCTL(DRM_IOCTL_MODE_DETACHMODE, 0, 0),
  IOCTL(DRM_IOCTL_MODE_GETPROPERTY, 0, 0),
  IOCTL(DRM_IOCTL_MODE_SETPROPERTY, 0, 0),
  IOCTL(DRM_IOCTL_MODE_GETPROPBLOB, 0, 0),
  IOCTL(DRM_IOCTL_MODE_GETFB, 0, 0),
  IOCTL(DRM_IOCTL_MODE_ADDFB, 0, 0),
  IOCTL(DRM_IOCTL_MODE_RMFB, 0, 0),
  IOCTL(DRM_IOCTL_MODE_PAGE_FLIP, 0, 0),
  IOCTL(DRM_IOCTL_MODE_DIRTYFB, 0, 0),
#ifdef DRM_IOCTL_MODE_CREATE_DUMB
  IOCTL(DRM_IOCTL_MODE_CREATE_DUMB, 0, 0),
#endif
#ifdef DRM_IOCTL_MODE_MAP_DUMB
  IOCTL(DRM_IOCTL_MODE_MAP_DUMB, 0, 0),
#endif
#ifdef DRM_IOCTL_MODE_DESTROY_DUMB
  IOCTL(DRM_IOCTL_MODE_DESTROY_DUMB, 0, 0),
#endif
#ifdef DRM_IOCTL_MODE_GETPLANERESOURCES
  IOCTL(DRM_IOCTL_MODE_GETPLANERESOURCES, 0, 0),
#endif
#ifdef DRM_IOCTL_MODE_GETPLANE
  IOCTL(DRM_IOCTL_MODE_GETPLANE, 0, 0),
#endif
#ifdef DRM_IOCTL_MODE_SETPLANE
  IOCTL(DRM_IOCTL_MODE_SETPLANE, 0, 0),
#endif
#ifdef DRM_IOCTL_MODE_ADDFB2
  IOCTL(DRM_IOCTL_MODE_ADDFB2, 0, 0),
#endif
#ifdef DRM_IOCTL_MODE_OBJ_GETPROPERTIES
  IOCTL(DRM_IOCTL_MODE_OBJ_GETPROPERTIES, 0, 0),
#endif
#ifdef DRM_IOCTL_MODE_OBJ_SETPROPERTY
  IOCTL(DRM_IOCTL_MODE_OBJ_SETPROPERTY, 0, 0),
#endif

#ifdef USE_DRM_EXYNOS
	/* exynos_drm.h */
  IOCTL(DRM_IOCTL_EXYNOS_GEM_CREATE, 0, 0),
#ifdef DRM_IOCTL_EXYNOS_GEM_MAP_OFFSET
  IOCTL(DRM_IOCTL_EXYNOS_GEM_MAP_OFFSET, 0, 0),
#endif
#ifdef DRM_IOCTL_EXYNOS_GEM_MMAP
  IOCTL(DRM_IOCTL_EXYNOS_GEM_MMAP, 0, 0),
#endif
#ifdef DRM_IOCTL_EXYNOS_GEM_GET
  IOCTL(DRM_IOCTL_EXYNOS_GEM_GET, 0, 0),
#endif
#ifdef DRM_IOCTL_EXYNOS_VIDI_CONNECTION
  IOCTL(DRM_IOCTL_EXYNOS_VIDI_CONNECTION, 0, 0),
#endif
#ifdef DRM_IOCTL_EXYNOS_G2D_GET_VER
  IOCTL(DRM_IOCTL_EXYNOS_G2D_GET_VER, 0, 0),
#endif
#ifdef DRM_IOCTL_EXYNOS_G2D_SET_CMDLIST
  IOCTL(DRM_IOCTL_EXYNOS_G2D_SET_CMDLIST, 0, 0),
#endif
#ifdef DRM_IOCTL_EXYNOS_G2D_EXEC
  IOCTL(DRM_IOCTL_EXYNOS_G2D_EXEC, 0, 0),
#endif
#endif

	/* i810_drm.h */
  IOCTL(DRM_IOCTL_I810_INIT, 0, 0),
  IOCTL(DRM_IOCTL_I810_VERTEX, 0, 0),
  IOCTL(DRM_IOCTL_I810_CLEAR, 0, 0),
  IOCTL(DRM_IOCTL_I810_FLUSH, 0, 0),
  IOCTL(DRM_IOCTL_I810_GETAGE, 0, 0),
  IOCTL(DRM_IOCTL_I810_GETBUF, 0, 0),
  IOCTL(DRM_IOCTL_I810_SWAP, 0, 0),
  IOCTL(DRM_IOCTL_I810_COPY, 0, 0),
  IOCTL(DRM_IOCTL_I810_DOCOPY, 0, 0),
  IOCTL(DRM_IOCTL_I810_OV0INFO, 0, 0),
  IOCTL(DRM_IOCTL_I810_FSTATUS, 0, 0),
  IOCTL(DRM_IOCTL_I810_OV0FLIP, 0, 0),
  IOCTL(DRM_IOCTL_I810_MC, 0, 0),
  IOCTL(DRM_IOCTL_I810_RSTATUS, 0, 0),
  IOCTL(DRM_IOCTL_I810_FLIP, 0, 0),

	/* i915_drm.h */
  IOCTL(DRM_IOCTL_I915_INIT, 0, 0),
  IOCTL(DRM_IOCTL_I915_FLUSH, 0, 0),
  IOCTL(DRM_IOCTL_I915_FLIP, 0, 0),
  IOCTL(DRM_IOCTL_I915_BATCHBUFFER, 0, 0),
  IOCTL(DRM_IOCTL_I915_IRQ_EMIT, 0, 0),
  IOCTL(DRM_IOCTL_I915_IRQ_WAIT, 0, 0),
  IOCTL(DRM_IOCTL_I915_GETPARAM, 0, 0),
  IOCTL(DRM_IOCTL_I915_SETPARAM, 0, 0),
  IOCTL(DRM_IOCTL_I915_ALLOC, 0, 0),
  IOCTL(DRM_IOCTL_I915_FREE, 0, 0),
  IOCTL(DRM_IOCTL_I915_INIT_HEAP, 0, 0),
  IOCTL(DRM_IOCTL_I915_CMDBUFFER, 0, 0),
  IOCTL(DRM_IOCTL_I915_DESTROY_HEAP, 0, 0),
  IOCTL(DRM_IOCTL_I915_SET_VBLANK_PIPE, 0, 0),
  IOCTL(DRM_IOCTL_I915_GET_VBLANK_PIPE, 0, 0),
  IOCTL(DRM_IOCTL_I915_VBLANK_SWAP, 0, 0),
#ifdef DRM_IOCTL_I915_HWS_ADDR
  IOCTL(DRM_IOCTL_I915_HWS_ADDR, 0, 0),
#endif
  IOCTL(DRM_IOCTL_I915_GEM_INIT, 0, 0),
  IOCTL(DRM_IOCTL_I915_GEM_EXECBUFFER, 0, 0),
  IOCTL(DRM_IOCTL_I915_GEM_EXECBUFFER2, 0, 0),
  IOCTL(DRM_IOCTL_I915_GEM_PIN, 0, 0),
  IOCTL(DRM_IOCTL_I915_GEM_UNPIN, 0, 0),
  IOCTL(DRM_IOCTL_I915_GEM_BUSY, 0, 0),
#ifdef DRM_IOCTL_I915_GEM_SET_CACHING
  IOCTL(DRM_IOCTL_I915_GEM_SET_CACHING, 0, 0),
#endif
#ifdef DRM_IOCTL_I915_GEM_GET_CACHING
  IOCTL(DRM_IOCTL_I915_GEM_GET_CACHING, 0, 0),
#endif
  IOCTL(DRM_IOCTL_I915_GEM_THROTTLE, 0, 0),
  IOCTL(DRM_IOCTL_I915_GEM_ENTERVT, 0, 0),
  IOCTL(DRM_IOCTL_I915_GEM_LEAVEVT, 0, 0),
  IOCTL(DRM_IOCTL_I915_GEM_CREATE, 0, 0),
  IOCTL(DRM_IOCTL_I915_GEM_PREAD, 0, 0),
  IOCTL(DRM_IOCTL_I915_GEM_PWRITE, 0, 0),
  IOCTL(DRM_IOCTL_I915_GEM_MMAP, 0, 0),
  IOCTL(DRM_IOCTL_I915_GEM_MMAP_GTT, 0, 0),
  IOCTL(DRM_IOCTL_I915_GEM_SET_DOMAIN, 0, 0),
  IOCTL(DRM_IOCTL_I915_GEM_SW_FINISH, 0, 0),
  IOCTL(DRM_IOCTL_I915_GEM_SET_TILING, 0, 0),
  IOCTL(DRM_IOCTL_I915_GEM_GET_TILING, 0, 0),
  IOCTL(DRM_IOCTL_I915_GEM_GET_APERTURE, 0, 0),
  IOCTL(DRM_IOCTL_I915_GET_PIPE_FROM_CRTC_ID, 0, 0),
  IOCTL(DRM_IOCTL_I915_GEM_MADVISE, 0, 0),
  IOCTL(DRM_IOCTL_I915_OVERLAY_PUT_IMAGE, 0, 0),
  IOCTL(DRM_IOCTL_I915_OVERLAY_ATTRS, 0, 0),
#ifdef DRM_IOCTL_I915_SET_SPRITE_COLORKEY
  IOCTL(DRM_IOCTL_I915_SET_SPRITE_COLORKEY, 0, 0),
#endif
#ifdef DRM_IOCTL_I915_GET_SPRITE_COLORKEY
  IOCTL(DRM_IOCTL_I915_GET_SPRITE_COLORKEY, 0, 0),
#endif
#ifdef DRM_IOCTL_I915_GEM_WAIT
  IOCTL(DRM_IOCTL_I915_GEM_WAIT, 0, 0),
#endif
#ifdef DRM_IOCTL_I915_GEM_CONTEXT_CREATE
  IOCTL(DRM_IOCTL_I915_GEM_CONTEXT_CREATE, 0, 0),
#endif
#ifdef DRM_IOCTL_I915_GEM_CONTEXT_DESTROY
  IOCTL(DRM_IOCTL_I915_GEM_CONTEXT_DESTROY, 0, 0),
#endif
#ifdef DRM_IOCTL_I915_REG_READ
  IOCTL(DRM_IOCTL_I915_REG_READ, 0, 0),
#endif

	/* mga_drm.h */
  IOCTL(DRM_IOCTL_MGA_INIT, 0, 0),
  IOCTL(DRM_IOCTL_MGA_FLUSH, 0, 0),
  IOCTL(DRM_IOCTL_MGA_RESET, 0, 0),
  IOCTL(DRM_IOCTL_MGA_SWAP, 0, 0),
  IOCTL(DRM_IOCTL_MGA_CLEAR, 0, 0),
  IOCTL(DRM_IOCTL_MGA_VERTEX, 0, 0),
  IOCTL(DRM_IOCTL_MGA_INDICES, 0, 0),
  IOCTL(DRM_IOCTL_MGA_ILOAD, 0, 0),
  IOCTL(DRM_IOCTL_MGA_BLIT, 0, 0),
  IOCTL(DRM_IOCTL_MGA_GETPARAM, 0, 0),
  IOCTL(DRM_IOCTL_MGA_SET_FENCE, 0, 0),
  IOCTL(DRM_IOCTL_MGA_WAIT_FENCE, 0, 0),
  IOCTL(DRM_IOCTL_MGA_DMA_BOOTSTRAP, 0, 0),

	/* nouveau_drm.h */
  IOCTL(DRM_IOCTL_NOUVEAU_GETPARAM, 0, 0),
  IOCTL(DRM_IOCTL_NOUVEAU_SETPARAM, 0, 0),
  IOCTL(DRM_IOCTL_NOUVEAU_CHANNEL_ALLOC, 0, 0),
  IOCTL(DRM_IOCTL_NOUVEAU_CHANNEL_FREE, 0, 0),
  IOCTL(DRM_IOCTL_NOUVEAU_GROBJ_ALLOC, 0, 0),
  IOCTL(DRM_IOCTL_NOUVEAU_NOTIFIEROBJ_ALLOC, 0, 0),
  IOCTL(DRM_IOCTL_NOUVEAU_GPUOBJ_FREE, 0, 0),
#ifdef DRM_IOCTL_NOUVEAU_GEM_NEW
  IOCTL(DRM_IOCTL_NOUVEAU_GEM_NEW, 0, 0),
#endif
#ifdef DRM_IOCTL_NOUVEAU_GEM_PUSHBUF
  IOCTL(DRM_IOCTL_NOUVEAU_GEM_PUSHBUF, 0, 0),
#endif
#ifdef DRM_IOCTL_NOUVEAU_GEM_CPU_PREP
  IOCTL(DRM_IOCTL_NOUVEAU_GEM_CPU_PREP, 0, 0),
#endif
#ifdef DRM_IOCTL_NOUVEAU_GEM_CPU_FINI
  IOCTL(DRM_IOCTL_NOUVEAU_GEM_CPU_FINI, 0, 0),
#endif
#ifdef DRM_IOCTL_NOUVEAU_GEM_INFO
  IOCTL(DRM_IOCTL_NOUVEAU_GEM_INFO, 0, 0),
#endif

	/* r128_drm.h */
  IOCTL(DRM_IOCTL_R128_INIT, 0, 0),
  IOCTL(DRM_IOCTL_R128_CCE_START, 0, 0),
  IOCTL(DRM_IOCTL_R128_CCE_STOP, 0, 0),
  IOCTL(DRM_IOCTL_R128_CCE_RESET, 0, 0),
  IOCTL(DRM_IOCTL_R128_CCE_IDLE, 0, 0),
  IOCTL(DRM_IOCTL_R128_RESET, 0, 0),
  IOCTL(DRM_IOCTL_R128_SWAP, 0, 0),
  IOCTL(DRM_IOCTL_R128_CLEAR, 0, 0),
  IOCTL(DRM_IOCTL_R128_VERTEX, 0, 0),
  IOCTL(DRM_IOCTL_R128_INDICES, 0, 0),
  IOCTL(DRM_IOCTL_R128_BLIT, 0, 0),
  IOCTL(DRM_IOCTL_R128_DEPTH, 0, 0),
  IOCTL(DRM_IOCTL_R128_STIPPLE, 0, 0),
  IOCTL(DRM_IOCTL_R128_INDIRECT, 0, 0),
  IOCTL(DRM_IOCTL_R128_FULLSCREEN, 0, 0),
  IOCTL(DRM_IOCTL_R128_GETPARAM, 0, 0),
  IOCTL(DRM_IOCTL_R128_FLIP, 0, 0),

	/* radeon_drm.h */
  IOCTL(DRM_IOCTL_RADEON_CP_INIT, 0, 0),
  IOCTL(DRM_IOCTL_RADEON_CP_START, 0, 0),
  IOCTL(DRM_IOCTL_RADEON_CP_STOP, 0, 0),
  IOCTL(DRM_IOCTL_RADEON_CP_RESET, 0, 0),
  IOCTL(DRM_IOCTL_RADEON_CP_IDLE, 0, 0),
  IOCTL(DRM_IOCTL_RADEON_RESET, 0, 0),
  IOCTL(DRM_IOCTL_RADEON_FULLSCREEN, 0, 0),
  IOCTL(DRM_IOCTL_RADEON_SWAP, 0, 0),
  IOCTL(DRM_IOCTL_RADEON_CLEAR, 0, 0),
  IOCTL(DRM_IOCTL_RADEON_VERTEX, 0, 0),
  IOCTL(DRM_IOCTL_RADEON_INDICES, 0, 0),
  IOCTL(DRM_IOCTL_RADEON_STIPPLE, 0, 0),
  IOCTL(DRM_IOCTL_RADEON_INDIRECT, 0, 0),
  IOCTL(DRM_IOCTL_RADEON_TEXTURE, 0, 0),
  IOCTL(DRM_IOCTL_RADEON_VERTEX2, 0, 0),
  IOCTL(DRM_IOCTL_RADEON_CMDBUF, 0, 0),
  IOCTL(DRM_IOCTL_RADEON_GETPARAM, 0, 0),
  IOCTL(DRM_IOCTL_RADEON_FLIP, 0, 0),
  IOCTL(DRM_IOCTL_RADEON_ALLOC, 0, 0),
  IOCTL(DRM_IOCTL_RADEON_FREE, 0, 0),
  IOCTL(DRM_IOCTL_RADEON_INIT_HEAP, 0, 0),
  IOCTL(DRM_IOCTL_RADEON_IRQ_EMIT, 0, 0),
  IOCTL(DRM_IOCTL_RADEON_IRQ_WAIT, 0, 0),
  IOCTL(DRM_IOCTL_RADEON_CP_RESUME, 0, 0),
  IOCTL(DRM_IOCTL_RADEON_SETPARAM, 0, 0),
  IOCTL(DRM_IOCTL_RADEON_SURF_ALLOC, 0, 0),
  IOCTL(DRM_IOCTL_RADEON_SURF_FREE, 0, 0),
  IOCTL(DRM_IOCTL_RADEON_GEM_INFO, 0, 0),
  IOCTL(DRM_IOCTL_RADEON_GEM_CREATE, 0, 0),
  IOCTL(DRM_IOCTL_RADEON_GEM_MMAP, 0, 0),
  IOCTL(DRM_IOCTL_RADEON_GEM_PREAD, 0, 0),
  IOCTL(DRM_IOCTL_RADEON_GEM_PWRITE, 0, 0),
  IOCTL(DRM_IOCTL_RADEON_GEM_SET_DOMAIN, 0, 0),
  IOCTL(DRM_IOCTL_RADEON_GEM_WAIT_IDLE, 0, 0),
  IOCTL(DRM_IOCTL_RADEON_CS, 0, 0),
  IOCTL(DRM_IOCTL_RADEON_INFO, 0, 0),
#ifdef DRM_IOCTL_RADEON_GEM_SET_TILING
  IOCTL(DRM_IOCTL_RADEON_GEM_SET_TILING, 0, 0),
#endif
#ifdef DRM_IOCTL_RADEON_GEM_GET_TILING
  IOCTL(DRM_IOCTL_RADEON_GEM_GET_TILING, 0, 0),
#endif
  IOCTL(DRM_IOCTL_RADEON_GEM_BUSY, 0, 0),
#ifdef DRM_IOCTL_RADEON_GEM_VA
  IOCTL(DRM_IOCTL_RADEON_GEM_VA, 0, 0),
#endif

	/* savage_drm.h */
#ifdef DRM_IOCTL_SAVAGE_BCI_INIT
  IOCTL(DRM_IOCTL_SAVAGE_BCI_INIT, 0, 0),
#endif
#ifdef DRM_IOCTL_SAVAGE_BCI_CMDBUF
  IOCTL(DRM_IOCTL_SAVAGE_BCI_CMDBUF, 0, 0),
#endif
#ifdef DRM_IOCTL_SAVAGE_BCI_EVENT_EMIT
  IOCTL(DRM_IOCTL_SAVAGE_BCI_EVENT_EMIT, 0, 0),
#endif
#ifdef DRM_IOCTL_SAVAGE_BCI_EVENT_WAIT
  IOCTL(DRM_IOCTL_SAVAGE_BCI_EVENT_WAIT, 0, 0),
#endif

	/* sis_drm.h */
  IOCTL(DRM_IOCTL_SIS_FB_ALLOC, 0, 0),
  IOCTL(DRM_IOCTL_SIS_FB_FREE, 0, 0),
  IOCTL(DRM_IOCTL_SIS_AGP_INIT, 0, 0),
  IOCTL(DRM_IOCTL_SIS_AGP_ALLOC, 0, 0),
  IOCTL(DRM_IOCTL_SIS_AGP_FREE, 0, 0),
  IOCTL(DRM_IOCTL_SIS_FB_INIT, 0, 0)

	/* via_drm.h */
	/*
	IOCTL(DRM_IOCTL_VIA_ALLOCMEM),
	IOCTL(DRM_IOCTL_VIA_FREEMEM),
	IOCTL(DRM_IOCTL_VIA_AGP_INIT),
	IOCTL(DRM_IOCTL_VIA_FB_INIT),
	IOCTL(DRM_IOCTL_VIA_MAP_INIT),
	IOCTL(DRM_IOCTL_VIA_DEC_FUTEX),
	IOCTL(DRM_IOCTL_VIA_DMA_INIT),
	IOCTL(DRM_IOCTL_VIA_CMDBUFFER),
	IOCTL(DRM_IOCTL_VIA_FLUSH),
	IOCTL(DRM_IOCTL_VIA_PCICMD),
	IOCTL(DRM_IOCTL_VIA_CMDBUF_SIZE),
	IOCTL(DRM_IOCTL_VIA_WAIT_IRQ),
	IOCTL(DRM_IOCTL_VIA_DMA_BLIT),
	IOCTL(DRM_IOCTL_VIA_BLIT_SYNC),
	*/
};

static const char *const drm_devs[] = {
	"drm",
};

static const struct ioctl_group drm_grp = {
	.devtype = DEV_CHAR,
	.devs = drm_devs,
	.devs_cnt = ARRAY_SIZE(drm_devs),
	.sanitise = pick_random_ioctl,
	.ioctls = drm_ioctls,
	.ioctls_cnt = ARRAY_SIZE(drm_ioctls),
};

REG_IOCTL_GROUP(drm_grp)

#endif /* USE_DRM */
